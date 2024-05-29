# First Practicum of the Programming II Subject

## Project Overview
The idea of this practicum was to implement both static and dynamic implementations in C for the management of a music platform.

## Features
- **User Management:** 
  - Each item of the list of users contains:
    - A plan (basic or pro)
    - A list of songs

## Project Files
- Several test files are attached.
- Test code is included to verify functionality.

## Status
- The project has been submitted and approved, however I'm open to changes in order to improve it's efficiency.

# Program Usage

This program manages a list of users and their streaming activities. It supports the following operations:

- **New (N)**: Adds a new user to the end of the user list with the specified user category and initializes the stream count to 0. If a user with the same username already exists or the insertion could not be performed, an error message will be printed.

- **Delete (D)**: Locates and removes a user from the list. If there is no user with the given username or the list is empty, an error message will be printed.

- **Upgrade (U)**: Locates a user and upgrades their category to pro. If there is no user with the given username, the user already has a pro category, or the list is empty, an error message will be printed.

- **Play (P)**: Locates a user and increments their total stream count by 1. If there is no user with the given username or the list is empty, an error message will be printed.

- **Stats (S)**: Displays the whole list of current users and a table showing, for each user category, the number of users with that category, their number of songs played, and their average stream count (to two decimal places). If the user list is empty, an error message will be printed.

*It is important to specify that these operations must be introduced in a .txt file in the config.cmake file, the same happens when choosing the static or dynamic implementation.
```bash
#Choose between DYNAMIC or STATIC to use a concrete implementation (uncomment desired line)
#set(impl DYNAMIC)
set(impl STATIC)

#Choose the input file for main (new.txt, play.txt, upgrade.txt, delete1.txt...)
set(input stats_average_float.txt)
```
## Example

Here's an example of how to run the program with the new.txt file:
1. Modify the config.cmake file:
```bash
#set(impl DYNAMIC)
set(impl STATIC) //choose between static and dynamic implememtation

#Choose the input file for main (new.txt, play.txt, upgrade.txt, delete1.txt...)
set(input nex.txt)
```
- This is the new.txt file:
```bash
01 N user1 basic
02 S
03 N user2 pro
04 S
05 N user3 basic
06 S
07 N user1 pro
08 S
```
- Now follows the execution:
 
```bash
********************
01 N: user user1 category basic
* New: user user1 category basic
********************
02 S:
User user1 category basic numplays 0
Category  Users  Plays  Average
Basic         1      0     0.00
Pro           0      0     0.00
********************
03 N: user user2 category pro
* New: user user2 category pro
********************
04 S:
User user1 category basic numplays 0
User user2 category pro numplays 0
Category  Users  Plays  Average
Basic         1      0     0.00
Pro           1      0     0.00
********************
05 N: user user3 category basic
* New: user user3 category basic
********************
06 S:
User user1 category basic numplays 0
User user2 category pro numplays 0
User user3 category basic numplays 0
Category  Users  Plays  Average
Basic         2      0     0.00
Pro           1      0     0.00
********************
07 N: user user1 category pro
+ Error: New not possible
********************
08 S:
User user1 category basic numplays 0
User user2 category pro numplays 0
User user3 category basic numplays 0
Category  Users  Plays  Average
Basic         2      0     0.00
Pro           1      0     0.00

Process finished with exit code 0
```
- The same process will be followed for the rest of the .txt files

## Contributing
If you wish to contribute to this project, please fork the repository and create a pull request with your changes. For major changes, please open an issue first to discuss what you would like to change.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact
For any questions or inquiries, please open an issue on GitHub.

