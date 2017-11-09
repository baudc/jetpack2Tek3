# jetpack2Tek3

The goal of this project is to create a game like Jetpack Joyride in team of two and in one week (School project)

Server usage : ./serverJ2T3 -p \<port> -g \<gravity> -m \<map>

Client usage : ./clientJ2T3 -h \<ip> -p \<port>

Press space to fire and release to stop.

Implemented protocol :

ID -> ask for its ID (positive and unique) through the client.

client request: ID

server response: ID \<value>

MAP -> ask for the map through the client.

client request: MAP

server response: MAP \<width> \<height> \<cells>, where \<cells> is a character string of length \<width>*\<height> that
represents the map’s contents (’\_’ for an empty space, ’c’ for a coin and ’e’ for an electric square)

READY -> tells the client that it has received its id and map and that it’s waiting for the game to start.

client message: READY

FIRE -> tell the client about the change in the state of the jetpack (’0’ if deactivated, ’1’ if activated).

client message: FIRE \<state>

START -> tells the server that the 2 players are connected and ready and that the game is beginning.

server message: START

PLAYER -> sends , on the server’s behalf, the state of a player.

server message: PLAYER \<playerID> \<x> \<y> \<score>

COIN -> tells the server that a player has found a coin.

server message: COIN \<playerID> \<x> \<y>

FINISH -> tells the server that the game is over and who the winner is.

server message: FINISH \<winnerID> or FINISH -1 if there is no winner.
