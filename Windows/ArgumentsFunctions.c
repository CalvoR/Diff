

// control on the number and the "-" of each argument

unsigned int ArgumentsControl (int argc, char** argv)
{
    if (argc < 3)   {
        printf("Too few arguments to execute the command\n");
        return 0;
    }

    int i=0;
    for (i=3; i<argc; i++)     {
        if (argv[i][0] != '-')  {
            printf("Error in one of the arguments\n");
            return 0;
        }
    }
    return 1;
}
