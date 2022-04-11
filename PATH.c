int main(int argc __attribute__((unused)), char **argv __attribute__((unused)), char **env)
{
	char* token;

	while (strncmp(*env, "PATH=", strlen("PATH=")) != 0)
		env++;

	token = strtok(env, ":");
 
    while (token != NULL) 
    {
		if token 

        printf("%s\n", token);
        token = strtok(NULL, ":");
    }
     return 0;
}

