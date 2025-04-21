#!/bin/bash -x

set -o errexit
set -o nounset

DOCKER_IMAGE_NAME=${DOCKER_IMAGE_NAME:-ceedling}
DOCKER_IMAGE_TAG=${DOCKER_IMAGE_TAG:-v0.31.1}
DOCKER_IMAGE=${DOCKER_IMAGE:-$DOCKER_IMAGE_NAME:$DOCKER_IMAGE_TAG}

# run container
docker run \
    --rm -it -w /project -v "$(pwd)/ab:/project" \
    "${DOCKER_IMAGE}" \
    /bin/bash