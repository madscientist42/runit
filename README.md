# runit

This is a fork of the runit init/services management framework originally 
developed by Gerrit Pape.  

To quote the original website: 
> runit is a cross-platform Unix init scheme with service supervision, a replacement 
> for sysvinit, and other init schemes. It runs on GNU/Linux, *BSD, MacOSX, Solaris, 
> and can easily be adapted to other Unix operating systems."

It is the primary init solution for many Linux distributions, and the optional (and 
often preferred, even though optional) one for many more.

The purpose of this fork is several-fold:

1. runit, while it works well enough for those distributions using it, hasn't had a real update in a while.
2. While it builds well enough, it is not geared to readily package into many distributions- it is packaged as a slashpackage.
3. While it builds well enough, it's build system is not geared for cross-compilation.
4. There needs to be a relatively credible alternative to systemd, this is one of the same.
5. While it is complete, and very capable, there are some aspects of fault tolerance not fully covered as well as they could be.

It is the intention of the long time Linux "Plumbers" that have undertaken this work to 
accomplish the above, providing a solid ecosystem around runit to provide what is believed 
to be a better answer to init/services management, that while it is differing from the 
sysv init structure that has gone before, is in keeping with the UNIX/*BSD/Linux philosophy
of doing only init/services management, leaving _*other*_ programs/schemes to handle udev, 
syslog, etc.

All decisions undertaken by this project are to be done by general consensus of the participants 
of this project.  Designs aren't to all be designed by committee, but any design decisions 
desired to be implemented into mainline is to be agreed upon by the members of this project.

