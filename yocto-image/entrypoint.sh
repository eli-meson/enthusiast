#!/bin/bash -xe

if [ -n "$USER_ID" ] && [ -n "$GROUP_ID" ]; then
	groupmod -o --gid "$GROUP_ID" builder
	usermod -o --uid "$USER_ID" --gid "$GROUP_ID" builder
	exec sudo -EHu builder "${@:-bash}"
else
	echo warning: USER_ID or GROUP_ID empty, running as root
	exec "${@:-bash}"
fi
