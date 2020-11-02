import Text.Printf
import Control.Concurrent
import Control.Concurrent.Async
import Network.HTTP

format_req :: String -> Integer -> Integer -> String
format_req mode note velocity = printf "http://192.168.4.1/%s?pitch=%d&velocity=%d" mode note velocity

note_req :: Integer -> IO ()
note_req midi_note = do
    threadDelay 100000
    print(midi_note)
    simpleHTTP (getRequest (format_req "on" midi_note 60))
    threadDelay 100000
    simpleHTTP (getRequest (format_req "off" midi_note 60))
    putStrLn ""

main = do
   let note_list = [22 .. 106]
   traverse note_req note_list
