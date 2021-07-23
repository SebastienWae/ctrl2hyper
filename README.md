# ctrl2hyper
Remap Left Ctrl to Hyper (Ctrl, Alt, Super).

This is an [Interception Tools](https://gitlab.com/interception/linux/tools) plugins that remaps all Left Ctrl key presses to mock the Hyper key, as it used to exist on the [Space-cadet keyboard](https://wikipedia.org/wiki/Space-cadet_keyboard), by pressing a combination of Ctrl, Alt and Super.

Works globally, no requirement of X11 or any graphics.

## Building
```shell
$ git clone https://github.com/sebastienwae/ctrl2hyper.git
$ cd ctrl2hyper
$ cmake -B build -DCMAKE_BUILD_TYPE=Release
$ cmake --build build
```

## Nix


## Execution
This plugin in meant to be used in combination with the Interception Tools plugin [caps2esc](https://gitlab.com/interception/linux/caps2esc).

Here is a suggested `udevmon` job configuration:
```yaml
- JOB: intercept -g $DEVNODE | ctrl2hyper | caps2esc -m 2 | uinput -d $DEVNODE
  DEVICE:
    EVENTS:
      EV_KEY: [KEY_CAPSLOCK, KEY_ESC, KEY_RIGHTCTRL, KEY_LEFTCTRL]
```
