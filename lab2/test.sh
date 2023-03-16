#! /bin/sh
#init
function pause(){
    read -p "$*"
}
	gcc -o unique_unsorted unique.c unsorted.c -std=c99

	gcc -o parity_unsorted parity.c unsorted.c -std=c99

	gcc -o unique_sorted unique.c sorted.c -std=c99

	gcc -o parity_sorted parity.c sorted.c
	echo "uniqueUnsorted" >> unsortedTimes.txt
	(time ./unique_unsorted /scratch/coen12/GreenEggsAndHam.txt ;)  2>> unsortedTimes.txt

	(time ./unique_unsorted /scratch/coen12/Macbeth.txt ;)  2>>  unsortedTimes.txt

	(time ./unique_unsorted /scratch/coen12/Genesis.txt  ;)  2>>  unsortedTimes.txt

	(time ./unique_unsorted /scratch/coen12/HoundOfTheBaskervilles.txt  ;)  2>>  unsortedTimes.txt

	(time ./unique_unsorted /scratch/coen12/TheWarOfTheWorlds.txt  ;)  2>>  unsortedTimes.txt

	(time ./unique_unsorted /scratch/coen12/TreasureIsland.txt  ;)  2>>  unsortedTimes.txt

	(time ./unique_unsorted /scratch/coen12/TheSecretGarden.txt  ;)  2>>  unsortedTimes.txt

	(time ./unique_unsorted /scratch/coen12/TwentyThousandLeagues.txt  ;)  2>>  unsortedTimes.txt

	(time ./unique_unsorted /scratch/coen12/TheCountOfMonteCristo.txt  ;)  2>>  unsortedTimes.txt

	(time ./unique_unsorted /scratch/coen12/Bible.txt  ;)  2>>  unsortedTimes.txt
	echo "uniqueSorted"  >> sortedTimes.txt
	(time ./unique_sorted /scratch/coen12/GreenEggsAndHam.txt  ;)  2>>  sortedTimes.txt

	(time ./unique_sorted /scratch/coen12/Macbeth.txt  ;)  2>>  sortedTimes.txt

	(time ./unique_sorted /scratch/coen12/Genesis.txt  ;)  2>>  sortedTimes.txt

	(time ./unique_sorted /scratch/coen12/HoundOfTheBaskervilles.txt ;)  2>>  sortedTimes.txt

	(time ./unique_sorted /scratch/coen12/TheWarOfTheWorlds.txt  ;)  2>>  sortedTimes.txt

	(time ./unique_sorted /scratch/coen12/TreasureIsland.txt  ;)  2>>  sortedTimes.txt

	(time ./unique_sorted /scratch/coen12/TheSecretGarden.txt  ;)  2>>  sortedTimes.txt

	(time ./unique_sorted /scratch/coen12/TwentyThousandLeagues.txt  ;)  2>>  sortedTimes.txt

	(time ./unique_sorted /scratch/coen12/TheCountOfMonteCristo.txt ;)  2>>  sortedTimes.txt

	(time ./unique_sorted /scratch/coen12/Bible.txt ;)  2>>  sortedTimes.txt
	echo "parityUnsorted" >> unsortedTimes.txt
	(time ./parity_unsorted /scratch/coen12/GreenEggsAndHam.txt ;)  2>>  unsortedTimes.txt

	(time ./parity_unsorted /scratch/coen12/Macbeth.txt ;)  2>>  unsortedTimes.txt

	(time ./parity_unsorted /scratch/coen12/Genesis.txt ;)  2>>  unsortedTimes.txt

	(time ./parity_unsorted /scratch/coen12/HoundOfTheBaskervilles.txt ;)  2>>  unsortedTimes.txt

	(time ./parity_unsorted /scratch/coen12/TheWarOfTheWorlds.txt ;)  2>>  unsortedTimes.txt

	(time ./parity_unsorted /scratch/coen12/TreasureIsland.txt ;)  2>>  unsortedTimes.txt

	(time ./parity_unsorted /scratch/coen12/TheSecretGarden.txt ;)  2>>  unsortedTimes.txt

	(time ./parity_unsorted /scratch/coen12/TwentyThousandLeagues.txt ;)  2>>  unsortedTimes.txt

	(time ./parity_unsorted /scratch/coen12/TheCountOfMonteCristo.txt ;)  2>>  unsortedTimes.txt

	(time ./parity_unsorted /scratch/coen12/Bible.txt ;)  2>>  unsortedTimes.txt
	echo "paritySorted"  >> sortedTimes.txt
	(time ./parity_sorted /scratch/coen12/GreenEggsAndHam.txt  ;)  2>>  sortedTimes.txt

	(time ./parity_sorted /scratch/coen12/Macbeth.txt  ;)  2>>  sortedTimes.txt

	(time ./parity_sorted /scratch/coen12/Genesis.txt  ;)  2>>  sortedTimes.txt

	(time ./parity_sorted /scratch/coen12/HoundOfTheBaskervilles.txt  ;)  2>>  sortedTimes.txt

	(time ./parity_sorted /scratch/coen12/TheWarOfTheWorlds.txt  ;)  2>>  sortedTimes.txt

	(time ./parity_sorted /scratch/coen12/TreasureIsland.txt  ;)  2>>  sortedTimes.txt

	(time ./parity_sorted /scratch/coen12/TheSecretGarden.txt  ;)  2>>  sortedTimes.txt

	(time ./parity_sorted /scratch/coen12/TwentyThousandLeagues.txt  ;)  2>>  sortedTimes.txt

	(time ./parity_sorted /scratch/coen12/TheCountOfMonteCristo.txt  ;)  2>>  sortedTimes.txt

	(time ./parity_sorted /scratch/coen12/Bible.txt  ;)  2>>  sortedTimes.txt
	echo "END"
	pause 'Press [Enter]'
