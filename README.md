This is SuperEasy config framework - SEConfig

The structure is below:

"config.txt"
[Global]
Hello = 123

And then you can use 
SEConfig config("config.txt");
auto res = config.stringOf("Hello");
