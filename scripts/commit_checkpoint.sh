#!/usr/bin/env bash
set -euo pipefail

bash scripts/test.sh

git status

printf "\n请输入 commit message: "
read -r message

if [ -z "$message" ]; then
    echo "commit message 不能为空。"
    exit 1
fi

git add .
git commit -m "$message"

if git remote get-url origin >/dev/null 2>&1; then
    printf "检测到远程仓库 origin。现在 push 吗？输入 yes 才会 push: "
    read -r answer
    if [ "$answer" = "yes" ]; then
        git push
    else
        echo "已跳过 push。"
    fi
else
    echo "没有配置远程仓库 origin。本次 commit 已保存在本地。"
fi
