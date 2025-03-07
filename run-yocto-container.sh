#!/bin/bash -xe

WORKSPACE_BASE_IMAGE=yocto-image:v0.1

CONTAINER_USER_ID=$(id -u)
CONTAINER_GROUP_ID=$(id -g)

YOCTODIR=$(dirname "$(realpath "$0")")

docker_opts=()

if [ -d "$HOME/.ssh" ]; then
	echo "Mounting ~/.ssh/ inside the container"
	docker_opts+=(
		-v "$HOME/.ssh:/home/builder/.ssh:ro"
	)
fi

if [ -S "$SSH_AUTH_SOCK" ]; then
	echo "Passing ssh-agent socket inside the container"
	docker_opts+=(
		-v "$SSH_AUTH_SOCK:$SSH_AUTH_SOCK:rw"
		-e "SSH_AUTH_SOCK=$SSH_AUTH_SOCK"
	)
fi

docker run \
	--rm \
	-it \
	-e "USER_ID=$CONTAINER_USER_ID" \
	-e "GROUP_ID=$CONTAINER_GROUP_ID" \
	-v "$YOCTODIR:$YOCTODIR" \
	-w "$YOCTODIR" \
	--name "yocto-image" \
	"${docker_opts[@]}" \
	"$WORKSPACE_BASE_IMAGE" \
	"$@"
