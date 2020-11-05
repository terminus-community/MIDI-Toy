import Control.Concurrent (threadDelay)
import Data.Traversable (for)
import Network.HTTP (simpleHTTP, getRequest)
import Text.Printf (printf)

data Mode = On | Off

instance Show Mode where
	show On = "on"
	show Off = "off"

data Note = Note Integer
	deriving Show

data Velocity = Velocity Integer

endpoint :: Mode -> Note -> Velocity -> String
endpoint mode (Note note) (Velocity velocity) =
	printf "http://192.168.4.1/%s?pitch=%d&velocity=%d" (show mode) note velocity

play :: Note -> IO ()
play note = do
    threadDelay 100000
    print $ "Current: " <> show note
    simpleHTTP . getRequest . endpoint On note $ Velocity 60
    threadDelay 100000
    simpleHTTP . getRequest . endpoint Off note $ Velocity 60
    putStrLn ""

main = for [22 .. 106] $ play . Note
