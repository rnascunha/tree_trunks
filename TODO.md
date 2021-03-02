# TODO list

* Make a configurable scheme: some kind of formated output (like a printf format) so the user have a way to configure the output;

> :warning: all this MUST be processed at compile time. I don't know how... something like: `"{time}|{error_type_short}|{module}:{payload}"` output a printf-like format.

* Remove any MACRO (`TT_`...) to configure the tt namespace. 

> :warning: how to configure constexpr variables?

* Make time output format configurable;
* Add other configurable options like:
** Uptime: process uptime (for desktops) or device uptime (to embended). uptime function could be configurable;
** diff_time/module diff_time: the time difference between two messages (from same module). Must hold some state... 
** other...

* Overload some output types: like ip/ipv6 (struct sockaddr_in), byte_arrays, mac...
 	
> :warning: is this even possible?

* Remove the size template number manual dependecie. At config<>, log<> the N template type must be manually informed... 
* Make a better color/font compile time construct, without macros
* Check color support at compile/runtime (if at run time, how to change config?)
* type traits...
* Should template it the stream output?