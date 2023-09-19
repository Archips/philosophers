# Philosophers

This project is an implementation of the classic dining philosophers problem using threads and mutexes. The dining philosophers problem is a concurrency synchronization challenge that models a scenario where a group of philosophers sits at a round table and alternates between eating, thinking, and sleeping. To ensure that the philosophers can eat without conflicts, mutexes are used to protect the state of forks placed between them.

## Project Highlights
- Simulates the classic dining philosophers problem.
- Utilizes threads to represent each philosopher at the round table.
- Implements mutexes to protect the state of forks and avoid data races.
- Allows customization of the number of philosophers, time to die, time to eat, and time to sleep through command-line arguments.
- Provides optional termination condition based on the number of times each philosopher must eat.
- Logs the state changes of philosophers with accurate timestamps.
- Ensures that philosophers avoid starving and dying.

## Usage
1. Clone the repository to your local machine.
2. Navigate to the project directory.
3. Compile the source files using the provided Makefile.
4. Execute the `philo` program with the following command-line arguments:
    - `number_of_philosophers`: The number of philosophers and forks.
    - `time_to_die` (in milliseconds): The time limit for a philosopher to start eating before they die.
    - `time_to_eat` (in milliseconds): The time it takes for a philosopher to eat while holding two forks.
    - `time_to_sleep` (in milliseconds): The time a philosopher spends sleeping.
    - `[number_of_times_each_philosopher_must_eat]` (optional): If specified, the simulation stops when all philosophers have eaten at least this many times. Otherwise, it stops when a philosopher dies.

## Author
[Archibald Thirion](https://github.com/Archips)
