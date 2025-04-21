# Embedded development enthusiasts

## Yocto build for QEMU

Build docker with tools:

docker build -f yocto-image/Containerfile -t yocto-image:v0.1 ./yocto-image

Build project:

```
./run-yocto-container.sh kas build
```

Run QEMU:

```
./run-yocto-container.sh kas shell -c "runqemu slirp nographic"
```
