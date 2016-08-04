# CK2 County Title Creator

This is a small tool that is helpful for large total conversion mods of CK2.
 
Its purpose is to quickly assign characters county titles based on an input of provinces.
This works great if you want to have a shattered map that is primarily ruled by
independent counts.

****

## Instructions

1. To download this tool click [here](CountyTitleCreator.zip) 
2. Unzip the file to any desired location
3. Open the file settings.txt
    *  **Make sure that every attribute** (*everything to the right of the equals sign*) **specified is enclosed with double quotes,** e.g. `titlesPath = "titlePathValue"`
    *  **provincesPath** specifies the directory/folder from where the program should read province files
	  normally for mod this would be under `C:\Users\MyUserName\Documents\Paradox Interactive\Crusader Kings II\mod\MyModeName\history\provinces`
      	* Make sure your provinces files are named as "*ProvinceID - ProvinceName.txt*" e.g. `1 - Eston.txt`
    * **titlesPath** specifies the directory/folder in which the titles you want to
      assign are located, normally under `C:\Users\MyUserName\Documents\Paradox Interactive\Crusader Kings II\mod\MyModeName\history\titles`
	  **but I strongly suggest you make a copy of that folder and specify the copy in the `settings.txt` to avoid possible loss of original data.** 
	* **provincesRequiringTitles** specifies for which provinces titles will be assigned.
      You can assign titles as an inclusive list 1-10 or as single provinces or both.
		* For example `10-20 24 30-33` will generate titles for the provinces 10 to 20 inclusive, province 24 and provinces 30 to 33 inclusive. Make sure every statement is space separated.
    * **titleHolderDate** specifies the date at which the assigned character holds the given county title.
		* It must be of the form *year.month.day*, e.g. `titleHolderDate = "1066.10.29"`
    * **holderIDToProvinceIDMultiplier** specifies what will be the character's holder ID based on the province ID.
		* It is calculated as `characterHolderIDForProvinceX = provinceX_ID * holderIDToProvinceIDMultiplier`
		* For example if `holderIDToProvinceIDMultiplier = "100"` this means that the character's holder ID for province 7 will be 700. Since `7 * 100 = 700`
    * **numBracketsToSkip** specifies how many statements within brackets will be skipped in order to record the county holder ownership. This is ideal if you want to have display some history
		on a given title before assigning it.
        * For example if the title file `c_eston.txt` has the following:
			```
			600.1.1={
				law = agnatic_succession
				law = succ_gavelkind
			}
			605.1.1={
				liege=d_dayria
			}
			```
		   We can set `numBracketsToSkip = "2"` so that it skips the first 2 statements with brackets so that the end result is something like this:
			```
			600.1.1={
				law = agnatic_succession
				law = succ_gavelkind
			}
			605.1.1={
				liege=d_dayria
			}			
			610.1.1={
				holder=100
			}
			```

****
[MIT License](LICENSE.md)
****
Created by [Aristotelis Sigiouan Leventidis](https://github.com/aristotle333)