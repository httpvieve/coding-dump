secret_word = "haechan"
guess = ""
# my sol'n :
counter = 3
while guess != secret_word and counter != 0:
        print("tries left : " + str(counter))
        guess = input("enter guess: ")
        counter -= 1
        
if guess == secret_word:
        print("Congrats!, you have guessed the secret word: " + secret_word)
elif guess != secret_word and counter == 0:
        print("You have no tries left!")
        
# freeCodeCamp sol'n :
guess_count = 0
guess_limit = 3
out_of_guesses = False
while guess != secret_word:
        if guess_count < guess_limit and not(out_of_guesses):
                guess = input("enter guess: ")
                guess_count += 1
        else:
                out_of_guesses = True
if out_of_guesses:
        print("You ran out of guesses! GAME OVER")
else:
        print("Congrats, YOU WIN! You have guessed the secret word: " + secret_word)