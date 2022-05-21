# Shop Vac Controller

 An Arduino Nano based project to provide automatic control for a small workshop vacuum by either sensing a tool use, or by a keyfob style remote control.

 Power control for the vacuum is provided by a 10A relay and the remote control by a small keyfob and reciever ( I used a [fob/reciever from Amazon](https://www.amazon.co.uk/gp/product/B08SHQ749R/)}.

Tool on/off sensing is provided by a small circuit using a cheap current transformer by **0033mer** I found on [YouTube](https://www.youtube.com/watch?v=gvBVxQGS_OU&t=280s) .

Both the sensitivity of the current sensor and the "*Turn Off*" delay for the vacuum control relay are adjustable by potentiometers.

The turn on delay for the remote control is 0s, the turn on delay for the power tool is nominaly set to 3s, but may be adjusted in the Arduino code. This helps to reduce the surge current created when both the power tool and the vacuum are turned on together.

The turn off delay for both the power tool and the remote fob can easily be adjusted between 3s and 30s with a potentiometer, this allows time for the wood chips and sawdust to be cleared from the vacuum hose.

It should be noted that if the vacuum is initiated by the mains powered tool turning on it can only be turned off by stopping the tool and in a similar way, if initiated by the remote fob it can only be turned off by the remote fob.

It is recommended that the vacuum power circuit includes a suitable fuse to protect the relay contacts.
