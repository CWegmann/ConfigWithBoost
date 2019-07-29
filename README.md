# ConfigWithBoost
Little demonstration how one can parse command line and config file arguments with boost


There are three sources for parameters:
- command line arguments
- config.ini file
- default values

There exist three possible parameters:
- "param01" (config.ini: 99, default value: 42)
- "param02" (config.ini: 1.234, default value: 3.1415)
- "param03" (config.ini: no value!, default value: "Hello, World!")

I list some possible program calls via command line and the resulting values:

With config.ini present, the results will be:

> ConfigWithBoost.exe

- param01 = 99 (from config.ini)
- param02 = 1.234 (from config.ini)
- param03 = Hello, World! (from default value)
   
> ConfigWithBoost.exe --param01 17 --param03 "Bye"

- param01 = 17 (from command line)
- param02 = 1.234 (from config.ini)
- param03 = "Bye" (from command line)

If you delete config.ini, the results will be:

> ConfigWithBoost.exe

- param01 = 42 (from default value)
- param02 = 3.1415 (from default value)
- param03 = Hello, World! (from default value)
   
> ConfigWithBoost.exe --param01 17 --param03 "Bye"

- param01 = 17 (from command line)
- param02 = 3.1415 (from default value)
- param03 = "Bye" (from command line)
