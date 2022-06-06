# Shop Vac Controller

 An Arduino Nano based project to provide automatic control for a small workshop vacuum by either sensing tool use, or by a keyfob style remote control.
<p align="center">
<img width="654" height="540" src="readme.images/SCH.Shop.Vac.Controller.png")
<p>
The four LED's display the status of the controller and its trigger source. It should be noted that the "Vac" LED flashes if a startup or shutdown delay is in progress.
<p align="center">
<img width="383" height="406" src="readme.images/SCH.Shop.Vac.Mains.png")
<p>
 Power control for the vacuum is provided by a 20A solid state relay and the remote control by a small keyfob and reciever ( I used a [fob reciever from Amazon](https://www.amazon.co.uk/gp/product/B08SHQ749R/)}.

Tool on/off sensing is provided by a small circuit by **0033mer** using a cheap current transformer  I found on [YouTube](https://www.youtube.com/watch?v=gvBVxQGS_OU&t=280s) .

Both the *sensitivity* of the current sensor and the *turn off* delay for the vacuum control relay are adjustable by preset potentiometers.

Whilst the remote has no turn-on delay, the vacuum turns on 3s after the power tool is started (this setting may be adjusted in the Arduino code). This delay helps to reduce the excessive surge current created if both the power tool and the vacuum are turned on together.

The turn-off delay is the same for both the power tool and the remote fob, and can easily be adjusted between 3s and 30s with a preset potentiometer, this allows time for the wood chips and sawdust to be cleared from the vacuum hose.

It should be noted that if the vacuum is initiated by the mains powered tool turning on it can only be turned off by stopping the tool and in a similar way, if initiated by the remote fob it can only be turned off by the remote fob.

It is recommended that the vacuum power circuit includes a suitable fuse.
