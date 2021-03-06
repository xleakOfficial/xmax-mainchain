# Configurations Documentation

# Table of contents
1. [Xmaxrun configuration - config.ini](#xmaxrunconf)
2. [Xmaxrun program options](#xmaxrunprogramopt)


<a name="xmaxrunconf"></a>
# Xmaxrun configuration

## Configuration file
The configuration file of `xmaxrun` program is a **ini** format file which locate in the `config` direcotry in the working directory or the same directory of the program. By default, its name is `config.ini` generated by the program at first run. It contains the options which affect the program behaviour at runtime. Below are the options instruction you can config in the configuration file.

## Configuration file options

### 1. **Plugin**

Option **plugin** specify the plugin class you want to use in the program, only the plugins and their dependencies in the configuration will be used by the program. The config value is the plugin derived class name in the program.

#### Example
```ini
plugin = MongoDBPlugin
plugin = BlockChainPlugin
plugin = BlockBuilderPlugin
```

<a name="xmaxrunprogramopt"></a>

# Xmaxrun program options

## Usage
You can pass some options as custom configurations when execute the **xmaxrun** program. Its format is:
```bash
xmaxrun --opt1 opt_value --opt2 opt_valu2 ...
```
Bellow will list the global options which supported in the program.

## **Help**
Option **help** show the command line options description and usage.
Its format is:
```bash
xmaxrun --help
```

