# List of ideas

## Queue

**HTTP MIDI radio**
It will be cool to have an Internet radio station for MIDI, controllable by its users.

**Vintage MIDI interfaces** (ones compatible with General MIDI)
There are [many](https://www.youtube.com/watch?v=eiMP-PlL6VM) MIDI compatible synthesizers and having several might be quite nice,
actually: `Roland SC-55 mk II`, `Yamaha MU80`, `Korg NS5R`.

## Ready

**Allow PUT and POST requests** (recommended by [SX](https://github.com/S-S-X/))

...And ignore the request body. Reason: simplicity, avoiding request caching. If there's any cache.

Code format is easier, as well:

```c++
server.on("/some/path", [](AsyncWebServerRequest *request){
  //do something useful
});
```
