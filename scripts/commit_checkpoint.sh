#!/usr/bin/env bash
set -euo pipefail

bash scripts/test.sh

git status

printf "\nCommit message: "
read -r message

if [ -z "$message" ]; then
    echo "Commit message is required."
    exit 1
fi

git add .
git commit -m "$message"

if git remote get-url origin >/dev/null 2>&1; then
    printf "Remote 'origin' exists. Push now? Type 'yes' to push: "
    read -r answer
    if [ "$answer" = "yes" ]; then
        git push
    else
        echo "Push skipped."
    fi
else
    echo "No remote 'origin' configured. Commit saved locally."
fi
