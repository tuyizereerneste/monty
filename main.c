#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

#define MAX_LINE_LENGTH 100

int main(int argc, char *argv[])
{
	        FILE *file;

		        char line[MAX_LINE_LENGTH];

			        unsigned int number = 1;

				        if (argc != 2)
						        {
	fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
	                return EXIT_FAILURE;
			        }
					        file = fopen(argv[1], "r");
						        if (file == NULL)
								        {
										                fprintf(stderr, "Error opening file: %s\n", argv[1]);
												                return EXIT_FAILURE;
														        }
							        while (fgets(line, sizeof(line), file))
									        {
											                strtok(line, "\n");
													                if (strncmp(line, "push", 4) == 0)
																                {
																			                int value = atoi(line + 5);
																					                push(value);
																							                }
															                else if (strcmp(line, "pall") == 0)
																	{
																		                        print_stack();
																					                }
																	                else if (strcmp(line, "swap") == 0)
																				                {
																							                        swap(&top, number);
																										                }
																			                else if (strcmp(line, "pint") == 0)
																					{
																						                        pint(&top, number);
																									                }
																					                else if (strcmp(line, "pop") == 0)
																								                {
																											                        pop(&top, number);
																														                }
																							                else if (strcmp(line, "add") == 0)
																										                {
																													                        add(&top,number);
																																                }
																			else if (strcmp(line, "sub") == 0)
																				                {
																							                        sub(&top,number);
																										                }
																			                number++;

																					        }
								        fclose(file);

									        return 0;
}
