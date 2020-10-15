
#include <iostream>
#include <map>
#include <vector>



namespace anagram
{

	struct anag
	{	
		std::vector<std::string> anagram_dict;

		void generate_anagram(std::vector<std::string>& input_phrase, const std::vector<std::string>& input_dict)
		{
			int l = 0;
			for (int i = 0; i < input_phrase.size(); i++)
			{
				for (int j = 0; input_phrase[i][j] != '\0'; j++)
				{
					//Compare every anagram of the input phrase to a word in the dictionary. If there is a match, then that word is an anagram.
					bool present = true;
					for (int k = j; ; k++)
					{
						if (k >= input_phrase[j].size() - 1 || k >= input_dict[l].size() - 1)
						{
							break;
						}

						if (input_dict[l][k] == input_phrase[j][k])
						{
							if ((k >= input_dict[l].size() - 1) && present == true)
							{
								l++;
								k = 0;
								anagram_dict.push_back(input_dict[l]);
							}							
						}
						else
						{
							present = false; // won't work for all cases. only straight forward cases.
						}
					}
				}
			}

			for (int i = 0; i < anagram_dict.size(); i++)
			{
				std::cout << anagram_dict[i] << std::endl;
			}
			
		}
	};

}

void main()
{
	std::vector<std::string> file_input = { "school", "cool", "pool", "pal", "rip", "dip", "ship" };
	std::vector<std::string> input_phrase = { "school principal"};

	anagram::anag anag_generator;
	anag_generator.generate_anagram(input_phrase, file_input);



}

