# List of ideas

**Allow PUT and POST requests**
...And ignore the request body. For simplicity and cache avoidance.
If there's any cache.

Code format will be easier:

```
server.on("/some/path", [](AsyncWebServerRequest *request){
  //do something useful
});
```

**HTTP MIDI radio**
It will be cool to have an Internet radio station for MIDI, controllable by its users.

**Vintage MIDI interfaces**
There are [many](https://www.youtube.com/watch?v=eiMP-PlL6VM) MIDI compatible synthesizers and having several might be quite nice,
actually.

