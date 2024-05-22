zombie = []
init = [[]]
game = []
temp = []
N, Q = input().split()
zombie = [int(zombie_total) for zombie_total in input().split()][:int(N)]
#for query in range(int(Q)):
game = [int(game_info) for game_info in input().split()][:5]
temp = game
stunned_dmg = game[0]
clip_size = game[1]
max_attacker = game[2]
limit = game[3]
zombie_dmg = game[4]

# goal = vaccine
MISSION = 0
hit_points = 9
pistol_dmg = 1

while MISSION == False:
        if len(zombie) > 0:
                if clip_size == 0:
                        clip_size = game[1]
                # else
  
                
                        
                        
                