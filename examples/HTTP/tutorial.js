// Running:
// node tutorial.js

// Based on this example:
// https://stackoverflow.com/questions/1795100

const http = require('http')

const min_note = 22,
      max_note = 106,
      note_delay = 30

// Increments note value, switches notes on and off
const update_note = (() => {
  let note_on = false
  let note = min_note
  return () => {
    if (note_on) {
        http.get(`http://192.168.4.1/off?pitch=${note}&velocity=60`)
        note++
    }
    else {
        http.get(`http://192.168.4.1/on?pitch=${note}&velocity=60`)
        console.log('Playing', note)
    }
    note_on = !note_on
    return note
  }
})()

const play_interval = setInterval(
  () => {
    const note_id = update_note()
    if (note_id > max_note) {
      clearInterval(play_interval)
      return
    }
  },
  note_delay
);
