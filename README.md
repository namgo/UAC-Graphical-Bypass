#Macro-ing UAC Prompts


## What is this?

I was curious as to if I can send <VK_LEFT> and <VK_RETURN> to a UAC prompt as soon as it pops up, a fairly graphical not-really-bypass way to interact with UAC for potential malice.

I thought, how could nobody have done this before?  Well, as it turns out, I didn't give MS enough credit.  I'm still not very comfortable with windows API but I think one of two things are happening, one possibility is that I simply didn't get the handle right, maybe there was more error checking I needed to do to see if the handle was correct.  More realistically however I would assume that I'm not the first person to think of this and that Microsoft's dev team forbids sending keys to certain applications.

## Cool side note however
~I believe that `IsCurrentWindowBlank(HWND handle)` does correctly demonstrate how one might observe whether a UAC prompt is open.  This could however be an indication that I don't know what I'm doing and that windows forbids reading numerous other types of application's window handles.~

## Did you see something I didn't?

Feel free to email me (address contained on my github profile) or hit me up on Freenode in which I'm nicked "nabam"

## Further reading
http://www.vistax64.com/vista-security/67070-uac-blocks-windows-messages.html
http://stackoverflow.com/questions/10562877/why-does-the-sendmessage-function-not-work

User Interface Privilege Isolation: http://en.wikipedia.org/wiki/User_Interface_Privilege_Isolation
https://social.msdn.microsoft.com/Forums/en-US/b68a77e7-cd00-48d0-90a6-d6a4a46a95aa/sendinput-fail-beause-interface-privilege-isolation-uipi-and-integrity
http://blogs.msdn.com/b/vishalsi/archive/2006/11/30/what-is-user-interface-privilege-isolation-uipi-on-vista.aspx

If I would have used `GetLastError()` I probably would have figured this out sooner.

Anything trying to inject code or messages to UAC will fail unless it's properly authorized.  Sending raw keyboard input would do it, but as far as I know windows provides no way to do this without interfacing with a driver directly.

I was incorrect about the blank window thing being a sign of UAC, the window handle was NULL.