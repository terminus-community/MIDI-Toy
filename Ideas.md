# List of ideas

## Queue

**HTTP MIDI radio**
It will be cool to have an Internet radio station for MIDI, controllable by its users.

**Vintage MIDI interfaces**
There are [many](https://www.youtube.com/watch?v=eiMP-PlL6VM) MIDI compatible synthesizers and having several might be quite nice,
actually.

## Ready

**Allow PUT and POST requests** (recommended by [SX](https://github.com/S-S-X/))

...And ignore the request body. Reason: simplicity, avoiding request caching. If there's any cache.

Code format is easier, as well:

```c++
server.on("/some/path", [](AsyncWebServerRequest *request){
  //do something useful
});
```
