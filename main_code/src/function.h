#include <Arduino.h>

// motor1 model:17HS4023
void motor1()
{
    // Required to define the parameters of a stepper motor
    list_data = 0;
    steps_motor1 = 0;
    speed_motor1 = 0;
    set_direction1 = 0;
    set_direction_side1 = 0;
    change_parameter = 0;
    // Required to define the parameters of a stepper motor

    // close all program
    close_while_case_1 = 0;
    close_zlozona = 0;
    back_to_mainu = 0;
    // close all program

    // variable to calculate how many steps the motor must take
    count1 = 0;
    // variable to calculate how many steps the motor must take
    BT.println("Selected motor: 1");
    delay(400);
    BT.println("1 Number of rotations => 1,2,3,4,..");
    delay(400);
    BT.println("2 Direction => 0: left 1: right");
    delay(400);
    BT.println("3: speed => <100 200 .. 4000>");
    delay(400);
    BT.println(" ");
    delay(400);

    // function to back for main menu
    while (back_to_mainu == 0)
    {
        if (close_zlozona == 0)
        {
            BT.println("back to menu? => 1-tes or 2-no");
            close_zlozona++;
        }

        if (BT.available() > 0)
        {
            back_to_mainu = BT.parseInt();
            close_zlozona = 0;
        }
    }
    // function to back for main menu

    while (back_to_mainu == 1)
    {

        // Selecting how many steps the motor needs to rotate
        while (steps_motor1 == 0)
        {

            if (close_zlozona == 0)
            {
                BT.println("how many rotates");
                close_zlozona++;
            }

            if (BT.available() > 0)
            {
                steps_motor1 = BT.parseInt();
                close_zlozona = 0;
            }
        }
        // Selecting how many steps the motor needs to rotate

        delay(400);

        // Selecting the direction in which the motor will rotate
        while (set_direction_side1 == 0)
        {

            if (close_zlozona == 0)
            {
                BT.println("direction of motor");
                close_zlozona++;
            }

            if (BT.available() > 0)
            {
                set_direction1 = BT.parseInt();
                close_zlozona = 0;

                if (set_direction1 == 1)
                {
                    set_direction_side1 = 1;
                }

                if (set_direction1 == 0)
                {
                    set_direction_side1 = -1;
                }

                if (set_direction1 > 0 || set_direction1 < 0)
                {
                    set_direction1 = 0;
                }
            }
        }
        // Selecting the direction in which the motor will rotate

        delay(400);

        // Choosing the speed that the motor must have
        while (speed_motor1 == 0)
        {

            if (close_zlozona == 0)
            {
                BT.println("speed of motor");
                close_zlozona++;
            }

            if (BT.available() > 0)
            {
                close_zlozona = 0;
                speed_motor1 = BT.parseInt();
            }
        }
        // Choosing the speed that the motor must have

        delay(400);

        // Function to modify values that were entered earlier
        while (change_parameter == 0)
        {
            if (close_zlozona == 0)
            {
                BT.println("Do you want to change any parameter?");
                delay(400);
                BT.println("1 => no");
                delay(400);
                BT.println("2 => Change the number of rotations");
                delay(400);
                BT.println("3 => Change the direction of motor");
                delay(400);
                BT.println("4 => Change the speed of motor");
                delay(400);
                close_zlozona++;
            }

            if (BT.available() > 0)
            {
                change_parameter = BT.parseInt();
                close_zlozona = 0;
                switch (change_parameter)
                {
                case 1:
                    change_parameter = 1;
                    break;
                case 2:
                    while (change_parameter != 0)
                    {
                        if (close_zlozona == 0)
                        {

                            BT.println("how many rotates");
                            close_zlozona++;
                        }
                        if (BT.available() > 0)
                        {
                            steps_motor1 = BT.parseInt();
                            close_zlozona = 0;
                            change_parameter = 0;
                        }
                    }
                    break;
                case 3:

                    while (change_parameter != 0)
                    {
                        if (close_zlozona == 0)
                        {

                            BT.println("direction of motor");
                            close_zlozona++;
                        }
                        if (BT.available() > 0)
                        {
                            set_direction1 = BT.parseInt();
                            close_zlozona = 0;

                            if (set_direction1 == 1)
                            {
                                set_direction_side1 = 1;
                                change_parameter = 0;
                            }

                            if (set_direction1 == 0)
                            {
                                set_direction_side1 = -1;
                                change_parameter = 0;
                            }
                        }
                    }
                    break;
                case 4:

                    while (change_parameter != 0)
                    {
                        if (close_zlozona == 0)
                        {

                            BT.println("speed of motor");
                            close_zlozona++;
                        }
                        if (BT.available() > 0)
                        {
                            speed_motor1 = BT.parseInt();
                            close_zlozona = 0;
                            change_parameter = 0;
                        }
                    }
                    break;
                }
            }
        }
        // Function to modify values that were entered earlier

        // Main function for starting the motor with the selected parameters
        if (change_parameter == 1)
        {

            count1 = set_direction_side1 * (steps_motor1 * 1600 + 25);

            if (speed_motor1 != 0 && set_direction_side1 != 0 && steps_motor1 != 0 && close_while_case_1 == 0)
            {

                stepper1.setMaxSpeed(speed_motor1);
                stepper1.setAcceleration(speed_motor1);
                stepper1.move(count1);
                stepper1.runToPosition();

                close_while_case_1++;
            }
            else
            {
                break;
            }
        }
        // Main function for starting the motor with the selected parameters
    }
}

// motor model:LDO-42STH48-2004MAC
void silnik2()
{
    // Required to define the parameters of a stepper motor
    list_data = 0;
    steps_motor2 = 0;
    speed_motor2 = 0;
    set_direction2 = 0;
    set_direction_side2 = 0;
    // Required to define the parameters of a stepper motor
    // close all program
    close_while_case_1 = 0;
    close_zlozona = 0;
    back_to_mainu = 0;
    change_parameter = 0;
    // close all program
    // variable to calculate how many steps the motor must take
    count2 = 0;
    // variable to calculate how many steps the motor must take
    BT.println("Selected motor: 2");
    delay(400);
    BT.println("1 Number of rotations => 1,2,3,4,..");
    delay(400);
    BT.println("2 Direction => 0: left 1: right");
    delay(400);
    BT.println("3: speed => <100 200 .. 4000>");
    delay(400);
    BT.println(" ");
    delay(400);

    // function to back for main menu
    while (back_to_mainu == 0)
    {
        if (close_zlozona == 0)
        {
            BT.println("back to menu? => 1-tes or 2-no");
            close_zlozona++;
        }

        if (BT.available() > 0)
        {
            back_to_mainu = BT.parseInt();
            close_zlozona = 0;
        }
    }
    // function to back for main menu

    while (back_to_mainu == 1)
    {

        // Selecting how many steps the motor needs to rotate
        while (steps_motor2 == 0)
        {

            if (close_zlozona == 0)
            {
                BT.println("how many rotates");
                close_zlozona++;
            }

            if (BT.available() > 0)
            {
                close_zlozona = 0;
                steps_motor2 = BT.parseInt();
            }
        }
        // Selecting how many steps the motor needs to rotate

        delay(400);

        // Selecting the direction in which the motor will rotate
        while (set_direction_side2 == 0)
        {

            if (close_zlozona == 0)
            {
                BT.println("direction of motor");
                close_zlozona++;
            }

            if (BT.available() > 0)
            {
                set_direction2 = BT.parseInt();
                close_zlozona = 0;

                if (set_direction2 == 1)
                {
                    set_direction_side2 = 1;
                }

                if (set_direction2 == 0)
                {
                    set_direction_side2 = -1;
                }

                if (set_direction2 > 0 || set_direction2 < 0)
                {
                    set_direction2 = 0;
                }
            }
        }
        // Selecting the direction in which the motor will rotate

        delay(400);

        // Choosing the speed that the motor must have
        while (speed_motor2 == 0)
        {

            if (close_zlozona == 0)
            {
                BT.println("speed of motor");
                close_zlozona++;
            }

            if (BT.available() > 0)
            {
                close_zlozona = 0;
                speed_motor2 = BT.parseInt();
            }
        }
        // Choosing the speed that the motor must have

        delay(400);

        // Function to modify values that were entered earlier
        while (change_parameter == 0)
        {
            if (close_zlozona == 0)
            {
                BT.println("Do you want to change any parameter?");
                delay(400);
                BT.println("1 => no");
                delay(400);
                BT.println("2 => Change the number of rotations");
                delay(400);
                BT.println("3 => Change the direction of motor");
                delay(400);
                BT.println("4 => Change the speed of motor");
                delay(400);
                close_zlozona++;
            }

            if (BT.available() > 0)
            {
                change_parameter = BT.parseInt();
                close_zlozona = 0;
                switch (change_parameter)
                {
                case 1:
                    change_parameter = 1;
                    break;
                case 2:
                    while (change_parameter != 0)
                    {
                        if (close_zlozona == 0)
                        {

                            BT.println("how many rotates");
                            close_zlozona++;
                        }
                        if (BT.available() > 0)
                        {
                            steps_motor2 = BT.parseInt();
                            close_zlozona = 0;
                            change_parameter = 0;
                        }
                    }
                    break;
                case 3:

                    while (change_parameter != 0)
                    {
                        if (close_zlozona == 0)
                        {

                            BT.println("direction of motor");
                            close_zlozona++;
                        }
                        if (BT.available() > 0)
                        {
                            set_direction2 = BT.parseInt();
                            close_zlozona = 0;

                            if (set_direction2 == 1)
                            {
                                set_direction_side2 = 1;
                                change_parameter = 0;
                            }

                            if (set_direction2 == 0)
                            {
                                set_direction_side2 = -1;
                                change_parameter = 0;
                            }
                        }
                    }
                    break;
                case 4:

                    while (change_parameter != 0)
                    {
                        if (close_zlozona == 0)
                        {

                            BT.println("speed of motor");
                            close_zlozona++;
                        }
                        if (BT.available() > 0)
                        {
                            speed_motor2 = BT.parseInt();
                            close_zlozona = 0;
                            change_parameter = 0;
                        }
                    }
                    break;
                }
            }
        }
        // Function to modify values that were entered earlier

        // Main function for starting the motor with the selected parameters
        if (change_parameter == 1)
        {

            count2 = set_direction_side2 * (steps_motor2 * 3200 + 25);

            if (speed_motor2 != 0 && set_direction_side2 != 0 && steps_motor2 != 0 && close_while_case_1 == 0)
            {

                stepper2.setMaxSpeed(speed_motor2);
                stepper2.setAcceleration(speed_motor2);
                stepper2.move(count2);
                stepper2.runToPosition();

                close_while_case_1++;
            }
            else
            {
                break;
            }
        }
        // Main function for starting the motor with the selected parameters
    }
}

// motor model:17HS4023 and  motor model:LDO-42STH48-2004MAC
void ruch_zlozony()
{

    // Required to define the parameters of a stepper motor
    list_data = 0;
    steps_motor1 = 0;
    speed_motor1 = 0;
    set_direction1 = 0;
    set_direction_side1 = 0;

    steps_motor2 = 0;
    speed_motor2 = 0;
    set_direction2 = 0;
    set_direction_side2 = 0;
    // Required to define the parameters of a stepper motor
    // close all program
    close_while_case_1 = 0;
    back_to_mainu = 0;
    change_parameter = 0;
    // close all program
    // variable to calculate how many steps the motor must take
    count1 = 0;
    count2 = 0;
    // variable to calculate how many steps the motor must take
    BT.println("Selected motor: 1,2");
    delay(400);
    BT.println("1 Number of rotations => 1,2,3,4,..");
    delay(400);
    BT.println("2 Direction => 0: left 1: right");
    delay(400);
    BT.println("3: speed => <100 200 .. 4000>");
    delay(400);
    BT.println(" ");
    delay(400);

    // function to back for main menu
    while (back_to_mainu == 0)
    {
        if (close_zlozona == 0)
        {
            BT.println("back to menu? => 1-tes or 2-no");
            close_zlozona++;
        }

        if (BT.available() > 0)
        {
            back_to_mainu = BT.parseInt();
            close_zlozona = 0;
        }
    }
    // function to back for main menu

    while (back_to_mainu == 1)
    {

        // Selecting how many steps the motor needs to rotate
        while (steps_motor1 == 0)
        {
            if (close_zlozona == 0)
            {
                BT.println("how many rotates_1");
                close_zlozona++;
            }
            if (BT.available() > 0)
            {
                close_zlozona = 0;
                steps_motor1 = BT.parseInt();
            }
        }
        // Selecting how many steps the motor needs to rotate

        delay(400);

        while (steps_motor2 == 0)
        {
            if (close_zlozona == 0)
            {
                BT.println("how many rotates_2");
                close_zlozona++;
            }
            if (BT.available() > 0)
            {
                close_zlozona = 0;
                steps_motor2 = BT.parseInt();
            }
        }
        // Selecting how many steps the motor needs to rotate

        delay(400);

        // Choosing the speed that the motor must have
        while (set_direction_side1 == 0)
        {
            if (close_zlozona == 0)
            {
                BT.println("direction of motor_1");
                close_zlozona++;
            }

            if (BT.available() > 0)
            {
                set_direction1 = BT.parseInt();
                close_zlozona = 0;

                if (set_direction1 == 1)
                {
                    set_direction_side1 = 1;
                }

                if (set_direction1 == 0)
                {
                    set_direction_side1 = -1;
                }

                if (set_direction1 > 0 || set_direction1 < 0)
                {
                    set_direction1 = 0;
                }
            }
        }

        delay(500);

        while (set_direction_side2 == 0)
        {

            if (close_zlozona == 0)
            {
                BT.println("direction of motor_2");
                close_zlozona++;
            }

            if (BT.available() > 0)
            {
                set_direction2 = BT.parseInt();
                close_zlozona = 0;

                if (set_direction2 == 1)
                {
                    set_direction_side2 = 1;
                }

                if (set_direction2 == 0)
                {
                    set_direction_side2 = -1;
                }

                if (set_direction2 > 0 || set_direction2 < 0)
                {
                    set_direction2 = 0;
                }
            }
        }
        // Choosing the speed that the motor must have

        delay(400);

        // Choosing the speed that the motor must have
        while (speed_motor1 == 0)
        {
            if (close_zlozona == 0)
            {
                BT.println("speed of motor_1");
                close_zlozona++;
            }
            if (BT.available() > 0)
            {
                close_zlozona = 0;
                speed_motor1 = BT.parseInt();
            }
        }

        delay(400);

        while (speed_motor2 == 0)
        {
            if (close_zlozona == 0)
            {
                BT.println("speed of motor_2");
                close_zlozona++;
            }
            if (BT.available() > 0)
            {
                close_zlozona = 0;
                speed_motor2 = BT.parseInt();
            }
        }
        // Choosing the speed that the motor must have

        delay(400);

        // Function to modify values that were entered earlier
        while (change_parameter == 0)
        {
            if (close_zlozona == 0)
            {
                BT.println("Do you want to change any parameter?");
                delay(400);
                BT.println("1 => no");
                delay(400);
                BT.println("2 => Change the number of rotations_1");
                delay(400);
                BT.println("3 => Change the direction of motor_1");
                delay(400);
                BT.println("4 => Change the speed of motor_1");
                delay(400);
                BT.println("3 => Change the number of rotations_2");
                delay(400);
                BT.println("5 => Change the direction of motor_2");
                delay(400);
                BT.println("7 => Change the speed of motor_2");
                delay(400);
                close_zlozona++;
            }

            if (BT.available() > 0)
            {
                change_parameter = BT.parseInt();
                close_zlozona = 0;
                switch (change_parameter)
                {
                case 1:
                    change_parameter = 1;
                    break;
                case 2:
                    while (change_parameter != 0)
                    {
                        if (close_zlozona == 0)
                        {

                            BT.println("how many rotates_1");
                            close_zlozona++;
                        }
                        if (BT.available() > 0)
                        {
                            steps_motor1 = BT.parseInt();
                            close_zlozona = 0;
                            change_parameter = 0;
                        }
                    }
                    break;
                case 3:

                    while (change_parameter != 0)
                    {
                        if (close_zlozona == 0)
                        {

                            BT.println("direction of motor_1");
                            close_zlozona++;
                        }
                        if (BT.available() > 0)
                        {
                            set_direction1 = BT.parseInt();
                            close_zlozona = 0;

                            if (set_direction1 == 1)
                            {
                                set_direction_side1 = 1;
                                change_parameter = 0;
                            }

                            if (set_direction1 == 0)
                            {
                                set_direction_side1 = -1;
                                change_parameter = 0;
                            }
                        }
                    }
                    break;
                case 4:

                    while (change_parameter != 0)
                    {
                        if (close_zlozona == 0)
                        {

                            BT.println("speed of motor_1");
                            close_zlozona++;
                        }
                        if (BT.available() > 0)
                        {
                            speed_motor1 = BT.parseInt();
                            close_zlozona = 0;
                            change_parameter = 0;
                        }
                    }
                    break;
                case 5:

                    while (change_parameter != 0)
                    {
                        if (close_zlozona == 0)
                        {

                            BT.println("how many rotates_2");
                            close_zlozona++;
                        }
                        if (BT.available() > 0)
                        {
                            steps_motor2 = BT.parseInt();
                            close_zlozona = 0;
                            change_parameter = 0;
                        }
                    }

                    break;

                case 6:

                    while (change_parameter != 0)
                    {
                        if (close_zlozona == 0)
                        {

                            BT.println("direction of motor_2");
                            close_zlozona++;
                        }
                        if (BT.available() > 0)
                        {
                            set_direction2 = BT.parseInt();
                            close_zlozona = 0;

                            if (set_direction2 == 1)
                            {
                                set_direction_side2 = 1;
                                change_parameter = 0;
                            }

                            if (set_direction2 == 0)
                            {
                                set_direction_side2 = -1;
                                change_parameter = 0;
                            }
                        }
                    }

                    break;

                case 7:

                    while (change_parameter != 0)
                    {
                        if (close_zlozona == 0)
                        {

                            BT.println("speed of motor_2");
                            close_zlozona++;
                        }
                        if (BT.available() > 0)
                        {
                            speed_motor2 = BT.parseInt();
                            close_zlozona = 0;
                            change_parameter = 0;
                        }
                    }

                    break;
                }
            }
        }
        // Choosing the speed that the motor must have

        // Main function for starting the motor with the selected parameters
        if (change_parameter == 1)
        {

            count1 = set_direction_side1 * (steps_motor1 * 1600 + 25);
            count2 = set_direction_side2 * (steps_motor2 * 3200 + 25);

            if (speed_motor1 != 0 && set_direction_side1 != 0 && steps_motor1 != 0 && speed_motor2 != 0 && set_direction_side2 != 0 && steps_motor2 != 0 && close_while_case_1 == 0)
            {

                stepper1.setMaxSpeed(speed_motor1);
                stepper1.setAcceleration(speed_motor1);
                stepper2.setMaxSpeed(speed_motor2);
                stepper2.setAcceleration(speed_motor2);

                if (count1 != 0 && count2 != 0)
                {

                    stepper1.move(count1);
                    stepper2.move(count2);
                }
                else
                {
                    stepper1.move(0);
                    stepper2.move(0);
                }

                while (stepper1.run() != 0 || stepper2.run() != 0)
                {
                    stepper1.run();
                    stepper2.run();
                }

                close_while_case_1++;
            }
            else
            {
                break;
            }
        }

        // Main function for starting the motor with the selected parameters
    }
}