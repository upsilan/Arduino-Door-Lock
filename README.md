Arduino Door Lock is a project for my room's door that is intended to be a cool way to open my door.

-Fingerprint based authentication
-Arduino based
-Supports enrolling and deleting fingerprints

USAGE GUIDE:
-the default code is 1234 and the user is expected to change it
-to change the code press #1 after which a beep should sound, then input your 4 digit code twice you should hear a long beep
 if you hear 3 short beeps it means both codes arenn't the same and the code was not changed.
-to add a fingerprint press #2 and wait for two beeps, authenticate, then press an ID number and press # again to enter it.
 then put your fingerprint 3 times (each ID is actually taking 3 internal ID's such that id N is N*3, N*3 + 1, N*3 + 2)
-to remove a fingerprint press #9 and wait for three beeps, then authenticate and select an ID to remove
-to exit any of these modes or to start inputing the code type *
