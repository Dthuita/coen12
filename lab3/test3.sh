#! /bin/sh
#init
function pause(){
    read -p "$*"
}
  gcc -o unique_hash unique.c hash.c

  gcc -o parity_hash parity.c hash.c

	echo "unique hash" >> hashTimes.txt
	(time ./unique_hash /scratch/coen12/GreenEggsAndHam.txt ;)  2>> hashTimes.txt

	(time ./unique_hash /scratch/coen12/Macbeth.txt ;)  2>>  hashTimes.txt

	(time ./unique_hash /scratch/coen12/Genesis.txt  ;)  2>>  hashTimes.txt

	(time ./unique_hash /scratch/coen12/HoundOfTheBaskervilles.txt  ;)  2>>  hashTimes.txt

	(time ./unique_hash /scratch/coen12/TheWarOfTheWorlds.txt  ;)  2>>  hashTimes.txt

	(time ./unique_hash /scratch/coen12/TreasureIsland.txt  ;)  2>>  hashTimes.txt

	(time ./unique_hash /scratch/coen12/TheSecretGarden.txt  ;)  2>>  hashTimes.txt

	(time ./unique_hash /scratch/coen12/TwentyThousandLeagues.txt  ;)  2>>  hashTimes.txt

	(time ./unique_hash /scratch/coen12/TheCountOfMonteCristo.txt  ;)  2>>  hashTimes.txt

	(time ./unique_hash /scratch/coen12/Bible.txt  ;)  2>>  hashTimes.txt
	echo "parity hash"  >> hashTimes.txt

  (time ./parity_hash /scratch/coen12/GreenEggsAndHam.txt ;)  2>> hashTimes.txt

  (time ./parity_hash /scratch/coen12/Macbeth.txt ;)  2>>  hashTimes.txt

  (time ./parity_hash /scratch/coen12/Genesis.txt  ;)  2>>  hashTimes.txt

  (time ./parity_hash /scratch/coen12/HoundOfTheBaskervilles.txt  ;)  2>>  hashTimes.txt

  (time ./parity_hash /scratch/coen12/TheWarOfTheWorlds.txt  ;)  2>>  hashTimes.txt

  (time ./parity_hash /scratch/coen12/TreasureIsland.txt  ;)  2>>  hashTimes.txt

  (time ./parity_hash /scratch/coen12/TheSecretGarden.txt  ;)  2>>  hashTimes.txt

  (time ./parity_hash /scratch/coen12/TwentyThousandLeagues.txt  ;)  2>>  hashTimes.txt

  (time ./parity_hash /scratch/coen12/TheCountOfMonteCristo.txt  ;)  2>>  hashTimes.txt

  (time ./parity_hash /scratch/coen12/Bible.txt  ;)  2>>  hashTimes.txt
