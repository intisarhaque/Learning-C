int addNewTeacher(void)
{
    char buffer[MAXNAMELENGTH];
    char ch;
    int i = 0;

    struct Teacher *newTeacher, *currentTeach = teacherHead;
    newTeacher = (struct Teacher *)malloc(sizeof(struct Teacher));

    int nameCheck = setNameToBuffer(buffer);
    if (nameCheck==1){
        return 1;
    }
    strcpy(newTeacher->name, buffer);

    printf("\nWhat subject does this teacher teach? ");
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
    else
    {
        int n = findOrAddSubjectCodeFromName(buffer);
        if (n == 0)
        {
            return 0;
        }
        newTeacher->subject = n;
        if (teacherHead == NULL)
        {
            teacherHead = newTeacher;
            printf("New teacher added successfully");
            return 0;
        }
        else
        {
            while (currentTeach->next != NULL)
            {
                currentTeach = currentTeach->next;
            }
            currentTeach->next = newTeacher;
            printf("New teacher added successfully");
            return 0;
        }
    }

}
