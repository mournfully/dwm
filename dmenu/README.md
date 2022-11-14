dmenu - dynamic menu
====================
dmenu is an efficient dynamic menu for X.

 - `dmenu`, a binary program.
 - `dmenu_run`, a wrapper shellscript to pipe `dmenu_path` into `dmenu`.
 - `dmenu_path`, a shellscript to deliver a list of executables.

Requirements
------------
In order to build dmenu you need the Xlib header files.


Installation
------------
Edit config.mk to match your local setup (dmenu is installed into
the /usr/local namespace by default).

Afterwards enter the following command to build and install dmenu
(if necessary as root):

    make clean install


Running dmenu
-------------
See the man page for details.
