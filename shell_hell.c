#include "shell.h"
#include "global_var.h"

int main(void)
{
	int continuar = 1;

	getcwd(PWD, maxln_Com_Amb);
	strcpy(PATH, getenv("PATH"));
	strcpy(HOME, PWD);
	strcpy(SHELL, PWD);

	do
	{
		//printf(" %s>", PWD);
		printf("Shell Hell $ ");
		__fpurge(stdin);
		memset(comando,'\0', maxln_Com_Amb);
		scanf("%[^\n]s", comando);

		if(strlen(comando) > 0)
		{
			separaArgs(); /*Separar comando de sus argumentos*/

			if(strcmp(comando,"cd") == 0)
			{
				if(args[1]) /* verify if additional parameters*/
				{
					if(chdir(args[1]) != 0)
						printf("Error: %s not found\n", args[1]);
					else
						getcwd(PWD,maxln_Com_Amb);
				}
			}
			else if(strcmp(comando,"dir") == 0)
				listaDir();
			else if(strcmp(comando,"clr") == 0)
				strcpy(comando,"clear"), comExterno();
			else if(strcmp(comando,"environ") == 0)
			{
				printf(" Environment variables:\n");
				printf("  HOME=%s\n  PWD=%s\n", HOME, PWD);
				printf("  SHELL=%s\n  PATH=%s\n", SHELL, PATH);
			}
			else if(strcmp(comando,"echo") == 0)
			{
				if(args[1])
					eco();
			}
			else if(strcmp(comando,"pwd") == 0)
				printf("%s\n", PWD);
			else if(strcmp(comando,"quit") == 0)
				continuar = 0; /*Cambiar el valor de continuar para que termine*/
			else comExterno(); /*Cualquier otra entrada llamar a comExterno*/
		}
	} while(continuar); /*Volver a ejecutar mientras no ingresen quit*/
	return 0;
}

void separaArgs(void)
{
	int i;

	for(i = 0; i < (max_args - 1); i++)
		args[i] = NULL; /*clear list of arguments*/

	strtok(comando," "), i = 0; /*spearate arguments in tokens*/
	args[i] = comando; /*1st argument is the command*/

	while((args[++i] = strtok(NULL," ")) != NULL && i < (max_args - 2));
}

void listaDir(void)
{
	char ruta[maxln_Com_Amb]; /*custom path string to be built*/
	int archs; /*Numero de archivos encontrados en el dir indicado*/
	int cnt =-1;
	struct dirent **lista; /*var que guarda la lista de archivos/dirs encontrados*/

	strcpy(ruta,PWD); /*Suponemos que el dir solicitado es de la ruta actual*/

	if(args[1])
	{
		strcat(ruta, "/");
		strcat(ruta, args[1]);
	}
		/*pero si se trata de una(s) subcarpeta(s) las concatenamos*/
	archs = scandir(ruta,&lista, 0, alphasort); /*Mandamos revisar el dir solicitado*/
	if(archs < 0) /*En caso de falla enviar mensaje*/
		printf("Error no existe o no se pudo leer [%s]\n", ruta);
	else if(archs == 2){ /*Si solo encontro los directorios . (actual) y .. (padre)
						 consideraremos que el dir esta vacio a efectos practicos*/
		printf(" El directorio [%s] esta vacio",ruta);
	}
	else{ /*Si se encontra al menos un archivo/directorio mostrarlo*/
		printf(" Archivos y carpetas encontrados en: [%s]\n", ruta);

		while(++cnt < archs)
		{
			if(strcmp(lista[cnt]->d_name,".") != 0 && strcmp(lista[cnt]->d_name,"..") != 0)
				printf(" %s\n",lista[cnt]->d_name);
		}
	}
}

void eco(void)
{
	unsigned int i;
	int j;
	int k = 0;
	char aux[6];
	while(args[++k])
	{ /*Aqui hay que recorrer argumento por  argumentos mientra este tenga valor*/
		for (i = 0; i < strlen(args[k]); i++)
		{ /*Para imprimir lo hare de caracter en caracter para 
										  interceptar el $ en caso de que este presente en cuanquier posicion*/
			if(args[k][i] != '$')
				printf("%c", args[k][i]);
			else
			{ /*Si se encuentra el $ ver si le sigue el nombre de alguna variable de ambiente 
					en caso afirmativo imprimir el valor correspondiente, sino imprimir el simbolo*/
				j=-1;
				while(++j < 5 && (i + j + 1) < strlen(args[k]) && args[k][i + j + 1] != '\0')
					aux[j] = args[k][i + j + 1]; /*En aux copiar la sub cadena que sigue al simbolo $*/

				aux[j] = '\0';

				if(strcmp(aux, "SHELL") == 0) /*Ver si hay que imprimir el valor de SHELL*/
					printf("%s", SHELL), i+=5;
				else if(strncmp(aux,"PATH",4) == 0) /*Idem PATH*/
					printf("%s", PATH), i+=4;
				else if(strncmp(aux,"PWD",3) == 0) /*Idem PWD*/
					printf("%s", PWD), i+=3;
				else if(strncmp(aux,"HOME",4) == 0) /*Idem HOME*/
					printf("%s", HOME), i+=4;
				else printf("$"); /*Ninguno de los anteriores el $ es solo un caracter mas*/
			}
		}
		printf(" "); /*Imprimir el espacio entre los distintos argumentos*/
	}
	printf("\n");
}

void comExterno()
{
	int pid = 0;
	int status;

	pid = fork(); /*Create subprocess*/

	if(pid < 0)
		printf("Error: Could not create process for this command.");

	if (pid == 0)
	{
		status=execvp(comando,args); /*Call command with args*/

		if(status)
		{
			printf("Error: %s not recognized\n", comando);
			exit(1);
		}
	}
	else
		wait(NULL); /* parent process hold runtime until child finishes */
}
