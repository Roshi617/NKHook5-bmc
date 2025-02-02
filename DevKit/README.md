# NKHook5 Mod Dev Kit (MDK)
This folder contains all of the files you need to get started, or even port over your existing mod, to NKHook5.

# Getting started
To ensure these tools work properly, make sure you have the following installed:

1. Python 3
2. Visual Studio Code
3. NKHook5 (in your game's folder)

# Setting up the MDK
To setup the NKH5 MDK, simply open this folder in Command Prompt, and run the following command:
```
devkit.exe --setup
```
This will ask you a few questions and then close. It will create an "mdkconf.json" file, which holds the responses you gave.

# Creating a mod
To create a new mod, run the following command:
```
devkit.exe --create-mod <mod-name>
```
Replace `<mod-name>` with the name of your mod. This will create a new mod workspace containing the
vanilla assets inside of the "Vanilla" folder. It will also create a "Mod" folder which will hold all of
your mod's assets. You will notice it comes with a "modinfo.json" file, which holds the name, version, description, author(s),
and any other information about your mod. Place your custom assets here.

# Testing your mod
To test your mod, run the following command:
```
devkit.exe --run-mod <mod-name>
```
This will launch BTD5 with the specified mod loaded.

# Packaging your mod
To create a mod package to distribute your mod, run the following command:
```
devkit.exe --package <mod-name>
```
This will calculate the difference between your modded json documents (and other files), generate new stripped json
documents with only the changed fields, and then put all necessary files into a `.zip` file. You can then share the .zip
file with anyone who has NKHook5. They simply place it into the "mods" folder, and launch the game.

# Updating your mod
To update your mod, simply run the following command:
```
devkit.exe --update <mod-name>
```
This will take the dump that was last made and update the mod to have that for the Vanilla resources instead.