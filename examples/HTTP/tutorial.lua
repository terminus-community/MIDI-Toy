-- This code is probably very bad
-- and I don't know how to make it faster.
-- If you know how to make it faster *in Lua*, please tell me.

-- Required for "sleep" function
-- local socket = require("socket")
local http = require("socket.http")

local min_note = 22
local max_note = 106
local note_delay = 30

for note = min_note, max_note do
   print('Note: ' .. note)
   http.request('http://192.168.4.1/on?pitch=' .. note .. '&velocity=30')
   -- Delay is not really needed, http in Lua seems sleepy enough.
   -- socket.sleep(note_delay / 1000)
   http.request('http://192.168.4.1/off?pitch=' .. note .. '&velocity=30')
   -- socket.sleep(note_delay / 1000)
end
