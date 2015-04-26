#Macro-ing UAC Prompts


## What is this?

I was curious as to if I can send <VK_LEFT> and <VK_RETURN> to a UAC prompt as soon as it pops up, a fairly graphical not-really-bypass way to interact with UAC for potential malice.

I thought, how could nobody have done this before?  Well, as it turns out, I didn't give MS enough credit.  I'm still not very comfortable with windows API but I think one of two things are happening, one possibility is that I simply didn't get the handle right, maybe there was more error checking I needed to do to see if the handle was correct.  More realistically however I would assume that I'm not the first person to think of this and that Microsoft's dev team forbids sending keys to certain applications.

## Cool side note however
I believe that `IsCurrentWindowBlank(HWND handle)` does correctly demonstrate how one might observe whether a UAC prompt is open.  This could however be an indication that I don't know what I'm doing and that windows forbids reading numerous other types of application's window handles.

## Did you see something I didn't?

Feel free to email me (address contained on my github profile) or hit me up on Freenode in which I'm nicked "nabam"