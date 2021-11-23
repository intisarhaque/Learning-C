int addNewStudent(void)
{
    //repeatable1
    char buffer[MAXNAMELENGTH],
    char ch = getchar();//does this get /\n?
    int i = 0, subject, j;
    struct Student *newStudent, *currentStudent = studentHead;
    //repeatable1

    newStudent = (struct Student *)malloc(sizeof(struct Student));
    newStudent->subjects = 1;
    newStudent->next = NULL;

    //repeatable2
    if (!isalpha(ch))
    {
        printf("The name can not be found, make sure you follow the correct search pattern\n");
        return 1;
    }
    while (ch != '\n' && i < MAXNAMELENGTH - 1)
    {
        buffer[i] = ch;
        ch = getchar();
        i++;
    }
    if (i == MAXNAMELENGTH - 1 && ch != '\n')
    {
        printf("This name is too long for our current system\n");
        return 1;
    }
    //repeatable2


    else
    {
        //repeatable3
        buffer[i] = '\0';
        strcpy(newStudent->name, buffer);
        j = 0;
        while (1)
        {
            printf("Enter a subject: ");
            ch = getchar();
            if (!isalpha(ch))
            {
                printf("The name can not be found, make sure you follow the correct search pattern\n");
                return 1;
            }
            i = 0;
            while (ch != '\n' && i < MAXNAMELENGTH - 1)
            {
                buffer[i] = ch;
                ch = getchar();
                i++;
            }
            buffer[i] = '\0';
            if (i == MAXNAMELENGTH - 1 && ch != '\n')
            {
                printf("This subject name is too long for our current system\n");
                return 1;
            }
            //repeatable3
            if (strcmp(buffer, "Done") == 0)
            {
                printf("Here\n");
                break;
            }
            printf("What grade is the student attaining in this subject, A,B,C,D,E,F,U or X if this is not known? ");
            ch = getchar();
            getchar();
            printf("%s\n", buffer);
            subject = findOrAddSubjectCodeFromName(buffer);
            newStudent->subjects = newStudent->subjects * subject;
            newStudent->grades[j] = ch;
            printf("%lu %s", newStudent->subjects, newStudent->grades);
            j++;
        }
        printf("here\n");
        newStudent->next = NULL;

        //repeatble4
        if (studentHead == NULL)
        {
            printf("here");
            studentHead = newStudent;
            return 0;
        }
        //repeatble4

        //repeatableN
        while (currentStudent->next != NULL)
        {
            currentStudent = currentStudent->next;
        }
        currentStudent->next = newStudent;
        printf("Student added successfully!\n");
        return 0;
        //repeatableN
    }
}
