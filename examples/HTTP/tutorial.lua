-- This code is probably very bad, because the requests are slow.
--
-- I don't know how to make those faster.
-- Some non-blocking requests, ignoring the response will help a lot.
-- If you happen to know how to make it faster *in Lua*, please tell me.

-- Required for "sleep" function
-- local socket = require("socket")

local http = require("socket.http")

local min_note = 22
local max_note = 106
local note_delay = 30
local velocity = 60

local note_req = function(mode, note, velocity)
    http.request({
        url='http://192.168.4.1/on?pitch=' .. note .. '&velocity=30',
        method='head',
        redirect=false
    })
    -- Delay is not really needed, http in Lua seems sleepy enough.
    -- socket.sleep(note_delay / 1000)
end

for note = min_note, max_note do
    print('Note: ' .. note)
    note_req('on', note, velocity)
    note_req('off', note, velocity)
end
