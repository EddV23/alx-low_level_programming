# DevOps Project: Bash Scripting

## 0x04. Loops, Conditions, and Parsing

## Overview

- This DevOps project focuses on Bash scripting, specifically involving loops, conditions, and log file parsing. The tasks cover a range of topics, from creating SSH key pairs to parsing Apache log files.

## General Requirements

### Tools

- Allowed editors: `vi`, `vim`, `emacs`
- Interpretation on Ubuntu 20.04 LTS
- All scripts must end with a newline
- A mandatory `README.md` file at the project root
- All Bash script files must be executable
- Use `Shellcheck` (version 0.7.0) to ensure error-free scripts
- First line of Bash scripts: `#!/usr/bin/env bash`
- Second line of Bash scripts: Comment explaining the script's purpose

### Shellcheck

- Use `Shellcheck` to ensure proper syntax and semantics
- Must pass `Shellcheck` without any errors

## Task 0: Create SSH RSA Key Pair

- Create an RSA key pair
- Share the public key in `0-RSA_public_key.pub`
- Fill the SSH public key field in your intranet profile
- Keep the private key secure
- Add a passphrase if desired (and store it securely)

### Example

```bash
# This script generates an RSA key pair
./0-RSA_public_key.pub
## Task 1: Display "Best School" with For Loop
- Use a for loop to display "Best School" 10 times
### Example
```bash
# This script displays "Best School" 10 times
./1-for_best_school

## Task 2: Display "Best School" with While Loop
- Use a while loop to display "Best School" 10 times
### Example
```bash
# This script displays "Best School" 10 times using a while loop
./2-while_best_school
```

## Task 3: Display "Best School" with Until Loop
- Use an until loop to display "Best School" 10 times
### Example
```bash
# This script displays "Best School" 10 times using an until loop
./3-until_best_school
```

## Task 4: Display "Best School" with Conditional Statement
- Use a while loop and an if statement
- Display "Hi" on the 9th iteration
### Example
```bash
# This script displays "Best School" 10 times and "Hi" on the 9th iteration
./4-if_9_say_hi
```

### Task 5: Display Messages with Conditions
- Use a while loop and if, elif, and else statements
- Display different messages based on iteration number
### Example
```bash
# This script displays messages based on loop iteration
./5-4_bad_luck_8_is_your_chance
```

## Task 6: Superstitious Numbers with Case Statement
- Use a while loop and a case statement
- Display messages based on loop iteration
### Example
```bash
# This script displays messages based on superstitious numbers
./6-superstitious_numbers
```

## Task 7: Display Time with While Loop
- Use a while loop to display hours and minutes
- Format output
### Example
```bash
# This script displays time for 12 hours and 59 minutes
./7-clock | head -n 70
```

## Task 8: List Files with For Loop
- Use a for loop to display the content of the current directory
- List only the part of the name after the first dash
### Example
```bash
# This script lists files in the current directory
./8-for_ls
```

## Task 9: Check and Display File Information
- Use if and else statements
- Check if a file exists, is empty, and its type
### Example
```bash
# This script checks and displays information about the school file
./9-to_file_or_not_to_file
```
## Task 10: FizzBuzz with While Loop
- Use a while loop to display numbers from 1 to 100
- Apply FizzBuzz conditions
### Example
```bash
# This script displays FizzBuzz for multiples of 3 and 5
./10-fizzbuzz | head -20
```

## Task 11: Read and Display /etc/passwd Information
- Use a while loop with IFS to display specific details from /etc/passwd
### Example
```bash
# This script displays username, user id, and home directory information
./100-read_and_cut
```

Task 12: Tell the Story of /etc/passwd
- Use a while loop with IFS to display a narrative based on /etc/passwd details
### Example
```bash
# This script parses Apache logs and displays visitor information
- ./102-lets_parse_apache_logs | tail -n 10
```

Task 13: Parse Apache Logs with Awk
- Use awk to parse Apache log files
- Display visitor IP addresses along with HTTP status codes

### Example
```bash
# This script parses Apache logs and displays visitor information
./102-lets_parse_apache_logs | tail -n 10
```

## Task 14: Group Visitors by IP and HTTP Status Code
- Use awk to group visitors by IP and HTTP status code
- Display the data in descending order of occurrences
### Example

```bash
# This script groups visitors by IP and HTTP status code
./103-dig_the-data | head -n 10
```

## License
- This project is licensed under the MIT License - see the LICENSE.md file for details.