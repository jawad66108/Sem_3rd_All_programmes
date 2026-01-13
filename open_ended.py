# import random

# # ============== GAME BOARD ==============
# def create_board():
#     return [' ' for _ in range(9)]

# def print_board(board):
#     for i in range(3):
#         print(board[i*3], '|', board[i*3+1], '|', board[i*3+2])
#         if i < 2:
#             print('---------')

# def get_moves(board):
#     return [i for i in range(9) if board[i] == ' ']

# def make_move(board, pos, player):
#     new_board = board.copy()
#     new_board[pos] = player
#     return new_board

# def check_winner(board):
#     wins = [(0,1,2),(3,4,5),(6,7,8),(0,3,6),(1,4,7),(2,5,8),(0,4,8),(2,4,6)]
#     for a,b,c in wins:
#         if board[a] == board[b] == board[c] != ' ':
#             return board[a]
#     if ' ' not in board:
#         return 'TIE'
#     return None

# # ============== STANDARD MINIMAX WITH ALPHA-BETA (AGENT A) ==============
# class AgentA:
#     def __init__(self, my_symbol, opp_symbol):
#         self.me = my_symbol
#         self.opp = opp_symbol
#         self.prune_count = 0
#         self.depth_limit = 9
        
#     def evaluate(self, board):
#         winner = check_winner(board)
#         if winner == self.me:
#             return 10
#         elif winner == self.opp:
#             return -10
#         return 0
    
#     def minimax(self, board, depth, is_max, alpha, beta):
#         winner = check_winner(board)
#         if winner or depth == 0:
#             return self.evaluate(board)
        
#         moves = get_moves(board)
#         if not moves:
#             return 0
            
#         if is_max:
#             best = -100
#             for move in moves:
#                 new_board = make_move(board, move, self.me)
#                 score = self.minimax(new_board, depth-1, False, alpha, beta)
#                 best = max(best, score)
#                 alpha = max(alpha, score)
#                 if beta <= alpha:
#                     self.prune_count += 1
#                     break
#             return best
#         else:
#             best = 100
#             for move in moves:
#                 new_board = make_move(board, move, self.opp)
#                 score = self.minimax(new_board, depth-1, True, alpha, beta)
#                 best = min(best, score)
#                 beta = min(beta, score)
#                 if beta <= alpha:
#                     self.prune_count += 1
#                     break
#             return best
    
#     def get_move(self, board):
#         best_move = None
#         best_score = -100
#         for move in get_moves(board):
#             new_board = make_move(board, move, self.me)
#             score = self.minimax(new_board, self.depth_limit, False, -100, 100)
#             if score > best_score:
#                 best_score = score
#                 best_move = move
#         return best_move

# # ============== ADAPTIVE AGENT WITH BEHAVIOR TRACKING (AGENT B) ==============
# class AgentB:
#     def __init__(self, my_symbol, opp_symbol):
#         self.me = my_symbol
#         self.opp = opp_symbol
#         self.prune_count = 0
#         self.depth_limit = 9
        
#         # MUTABLE DATA STRUCTURE FOR TRACKING
#         self.opp_moves = []
#         self.opp_pattern = {'corner': 0, 'edge': 0, 'center': 0}
#         self.random_count = 0
#         self.total_moves = 0
#         self.eval_weights = {'win': 10, 'lose': -10, 'center': 1, 'corner': 0.5}
#         self.deviation_threshold = 0.3
        
#     def track_move(self, move, board):
#         self.opp_moves.append(move)
#         self.total_moves += 1
        
#         if move == 4:
#             self.opp_pattern['center'] += 1
#         elif move in [0, 2, 6, 8]:
#             self.opp_pattern['corner'] += 1
#         else:
#             self.opp_pattern['edge'] += 1
        
#         was_rational = self.check_rational(move, board)
#         if not was_rational:
#             self.random_count += 1
            
#     def check_rational(self, move, board):
#         wins = [(0,1,2),(3,4,5),(6,7,8),(0,3,6),(1,4,7),(2,5,8),(0,4,8),(2,4,6)]
#         for a,b,c in wins:
#             positions = [board[a], board[b], board[c]]
#             if positions.count(self.opp) == 2 and positions.count(' ') == 1:
#                 empty_pos = [a,b,c][positions.index(' ')]
#                 if move == empty_pos:
#                     return True
#             if positions.count(self.me) == 2 and positions.count(' ') == 1:
#                 empty_pos = [a,b,c][positions.index(' ')]
#                 if move == empty_pos:
#                     return True
#         return False
    
#     def detect_deviation(self):
#         if self.total_moves < 3:
#             return False
#         random_ratio = self.random_count / self.total_moves
#         return random_ratio > self.deviation_threshold
    
#     def adapt_strategy(self):
#         if self.detect_deviation():
#             self.depth_limit = max(4, self.depth_limit - 1)
#             self.eval_weights['center'] = 2
#             self.eval_weights['corner'] = 1.5
#             return True
#         return False
        
#     def evaluate(self, board):
#         winner = check_winner(board)
#         if winner == self.me:
#             return self.eval_weights['win']
#         elif winner == self.opp:
#             return self.eval_weights['lose']
        
#         score = 0
#         if board[4] == self.me:
#             score += self.eval_weights['center']
#         for pos in [0, 2, 6, 8]:
#             if board[pos] == self.me:
#                 score += self.eval_weights['corner']
#         return score
    
#     def minimax(self, board, depth, is_max, alpha, beta):
#         winner = check_winner(board)
#         if winner or depth == 0:
#             return self.evaluate(board)
        
#         moves = get_moves(board)
#         if not moves:
#             return 0
            
#         if is_max:
#             best = -100
#             for move in moves:
#                 new_board = make_move(board, move, self.me)
#                 score = self.minimax(new_board, depth-1, False, alpha, beta)
#                 best = max(best, score)
#                 alpha = max(alpha, score)
#                 if beta <= alpha:
#                     self.prune_count += 1
#                     break
#             return best
#         else:
#             best = 100
#             for move in moves:
#                 new_board = make_move(board, move, self.opp)
#                 score = self.minimax(new_board, depth-1, True, alpha, beta)
#                 best = min(best, score)
#                 beta = min(beta, score)
#                 if beta <= alpha:
#                     self.prune_count += 1
#                     break
#             return best
    
#     def get_move(self, board):
#         self.adapt_strategy()
#         best_move = None
#         best_score = -100
#         for move in get_moves(board):
#             new_board = make_move(board, move, self.me)
#             score = self.minimax(new_board, self.depth_limit, False, -100, 100)
#             if score > best_score:
#                 best_score = score
#                 best_move = move
#         return best_move

# # ============== UNPREDICTABLE OPPONENT ==============
# class RandomOpponent:
#     def __init__(self, symbol, randomness=0.5):
#         self.symbol = symbol
#         self.randomness = randomness
        
#     def get_move(self, board):
#         moves = get_moves(board)
#         if random.random() < self.randomness:
#             return random.choice(moves)
#         wins = [(0,1,2),(3,4,5),(6,7,8),(0,3,6),(1,4,7),(2,5,8),(0,4,8),(2,4,6)]
#         for a,b,c in wins:
#             positions = [board[a], board[b], board[c]]
#             if positions.count(self.symbol) == 2 and positions.count(' ') == 1:
#                 return [a,b,c][positions.index(' ')]
#         return random.choice(moves)

# # ============== RUN GAMES ==============
# def play_game(agent, opponent, agent_tracker=None):
#     board = create_board()
#     turn = 'agent'
    
#     while True:
#         if turn == 'agent':
#             move = agent.get_move(board)
#             board = make_move(board, move, agent.me)
#             turn = 'opponent'
#         else:
#             move = opponent.get_move(board)
#             board = make_move(board, move, opponent.symbol)
#             if agent_tracker:
#                 agent_tracker.track_move(move, board)
#             turn = 'agent'
        
#         result = check_winner(board)
#         if result:
#             return result

# def run_comparison(num_games=20):
#     print("=" * 50)
#     print("AGENT COMPARISON: Standard vs Adaptive Minimax")
#     print("=" * 50)
    
#     results_a = {'WIN': 0, 'LOSE': 0, 'TIE': 0}
#     results_b = {'WIN': 0, 'LOSE': 0, 'TIE': 0}
#     logs = []
    
#     agent_a = AgentA('X', 'O')
#     agent_b = AgentB('X', 'O')
    
#     for game_num in range(1, num_games + 1):
#         seed = random.randint(1, 1000)
        
#         random.seed(seed)
#         opp_a = RandomOpponent('O', randomness=0.6)
#         agent_a.prune_count = 0
#         result_a = play_game(agent_a, opp_a)
#         prune_a = agent_a.prune_count
        
#         random.seed(seed)
#         opp_b = RandomOpponent('O', randomness=0.6)
#         agent_b.prune_count = 0
#         result_b = play_game(agent_b, opp_b, agent_b)
#         prune_b = agent_b.prune_count
        
#         if result_a == 'X':
#             results_a['WIN'] += 1
#         elif result_a == 'O':
#             results_a['LOSE'] += 1
#         else:
#             results_a['TIE'] += 1
            
#         if result_b == 'X':
#             results_b['WIN'] += 1
#         elif result_b == 'O':
#             results_b['LOSE'] += 1
#         else:
#             results_b['TIE'] += 1
        
#         log = {
#             'game': game_num,
#             'agent_a_result': result_a,
#             'agent_b_result': result_b,
#             'prune_a': prune_a,
#             'prune_b': prune_b,
#             'b_depth': agent_b.depth_limit,
#             'deviation_detected': agent_b.detect_deviation()
#         }
#         logs.append(log)
        
#         b_better = (result_b == 'X' and result_a != 'X') or (result_b == 'TIE' and result_a == 'O')
#         marker = " <-- AGENT B BETTER" if b_better else ""
#         print(f"Game {game_num}: A={result_a}, B={result_b}, Prunes(A={prune_a}, B={prune_b}), B_depth={agent_b.depth_limit}{marker}")

#     print("\n" + "=" * 50)
#     print("FINAL RESULTS SUMMARY")
#     print("=" * 50)
#     print(f"Agent A (Standard):  Wins={results_a['WIN']}, Losses={results_a['LOSE']}, Ties={results_a['TIE']}")
#     print(f"Agent B (Adaptive):  Wins={results_b['WIN']}, Losses={results_b['LOSE']}, Ties={results_b['TIE']}")
#     print(f"\nAgent B Total Prune Count: {sum(l['prune_b'] for l in logs)}")
#     print(f"Agent A Total Prune Count: {sum(l['prune_a'] for l in logs)}")
#     print(f"\nAgent B Opponent Pattern Tracking:")
#     print(f"  - Corner moves: {agent_b.opp_pattern['corner']}")
#     print(f"  - Edge moves: {agent_b.opp_pattern['edge']}")
#     print(f"  - Center moves: {agent_b.opp_pattern['center']}")
#     print(f"  - Random moves detected: {agent_b.random_count}/{agent_b.total_moves}")
#     print(f"  - Deviation detected: {agent_b.detect_deviation()}")
#     print(f"  - Final adapted depth: {agent_b.depth_limit}")
#     print(f"  - Adapted eval weights: {agent_b.eval_weights}")
    
#     b_wins = [l for l in logs if (l['agent_b_result'] == 'X' and l['agent_a_result'] != 'X') or 
#                                   (l['agent_b_result'] == 'TIE' and l['agent_a_result'] == 'O')]
#     print(f"\n*** Games where Agent B outperformed Agent A: {len(b_wins)} ***")
#     for l in b_wins:
#         print(f"  Game {l['game']}: A={l['agent_a_result']}, B={l['agent_b_result']}")
    
#     return logs

# run_comparison(20)


# import math
# import random
# from collections import defaultdict

# # ------------------------------
# # Game State
# # ------------------------------
# class NimState:
#     def __init__(self, stones, player):
#         self.stones = stones
#         self.player = player  # 1 = agent, -1 = opponent

#     def is_terminal(self):
#         return self.stones == 0

#     def get_legal_moves(self):
#         return [m for m in [1, 2] if self.stones - m >= 0]

#     def make_move(self, move):
#         return NimState(self.stones - move, -self.player)


# # ------------------------------
# # Minimax with Alpha-Beta
# # ------------------------------
# class Minimax:
#     def __init__(self, depth):
#         self.depth = depth
#         self.prune_count = 0

#     def evaluate(self, state):
#         if state.is_terminal():
#             return 100 if state.player == -1 else -100
#         return 0

#     def search(self, state, depth, alpha, beta, maximizing):
#         if depth == 0 or state.is_terminal():
#             return self.evaluate(state)

#         if maximizing:
#             value = -math.inf
#             for move in state.get_legal_moves():
#                 value = max(value, self.search(
#                     state.make_move(move),
#                     depth - 1,
#                     alpha,
#                     beta,
#                     False
#                 ))
#                 alpha = max(alpha, value)
#                 if alpha >= beta:
#                     self.prune_count += 1
#                     break
#             return value
#         else:
#             value = math.inf
#             for move in state.get_legal_moves():
#                 value = min(value, self.search(
#                     state.make_move(move),
#                     depth - 1,
#                     alpha,
#                     beta,
#                     True
#                 ))
#                 beta = min(beta, value)
#                 if beta <= alpha:
#                     self.prune_count += 1
#                     break
#             return value

#     def best_move(self, state):
#         best_score = -math.inf
#         best_action = None
#         for move in state.get_legal_moves():
#             score = self.search(
#                 state.make_move(move),
#                 self.depth - 1,
#                 -math.inf,
#                 math.inf,
#                 False
#             )
#             if score > best_score:
#                 best_score = score
#                 best_action = move
#         return best_action


# # ------------------------------
# # Adaptive Minimax Agent
# # ------------------------------
# class AdaptiveMinimax(Minimax):
#     def __init__(self, depth):
#         super().__init__(depth)
#         self.opponent_history = defaultdict(int)
#         self.total_moves = 0
#         self.deviation_score = 0

#     def observe_opponent(self, move, optimal_move):
#         self.total_moves += 1
#         self.opponent_history[move] += 1
#         if move != optimal_move:
#             self.deviation_score += 1

#     def irrationality_ratio(self):
#         if self.total_moves == 0:
#             return 0
#         return self.deviation_score / self.total_moves

#     def adapt_parameters(self):
#         ratio = self.irrationality_ratio()
#         if ratio > 0.3:
#             self.depth = min(6, self.depth + 1)
#         else:
#             self.depth = max(3, self.depth - 1)

#     def evaluate(self, state):
#         base = super().evaluate(state)
#         penalty = self.irrationality_ratio() * 20
#         return base - penalty


# # ------------------------------
# # Opponent Model (Unpredictable)
# # ------------------------------
# class UnpredictableOpponent:
#     def choose_move(self, state):
#         if random.random() < 0.4:
#             return random.choice(state.get_legal_moves())
#         else:
#             return min(state.get_legal_moves())


# # ------------------------------
# # Simulation
# # ------------------------------
# def play_match(agent, adaptive=False):
#     state = NimState(random.randint(10, 15), 1)
#     opponent = UnpredictableOpponent()

#     while not state.is_terminal():
#         if state.player == 1:
#             move = agent.best_move(state)
#             state = state.make_move(move)
#         else:
#             move = opponent.choose_move(state)
#             optimal = min(state.get_legal_moves())
#             if adaptive:
#                 agent.observe_opponent(move, optimal)
#                 agent.adapt_parameters()
#             state = state.make_move(move)

#     return -state.player


# # ------------------------------
# # Run Experiment
# # ------------------------------
# agent_A = Minimax(depth=4)
# agent_B = AdaptiveMinimax(depth=4)

# results = {
#     "Agent A wins": 0,
#     "Agent B wins": 0
# }

# for _ in range(50):
#     if play_match(agent_A) == 1:
#         results["Agent A wins"] += 1
#     if play_match(agent_B, adaptive=True) == 1:
#         results["Agent B wins"] += 1

# print("\n=== EXPERIMENT SUMMARY ===")
# print(results)
# print("\nAgent A pruning count:", agent_A.prune_count)
# print("Agent B pruning count:", agent_B.prune_count)
# print("Agent B irrationality ratio:",
#       round(agent_B.irrationality_ratio(), 2))


# import random
# import math
# from collections import defaultdict

# # ===============================
# # Dynamic Tic Tac Toe Environment
# # ===============================
# class DynamicTicTacToe:
#     def __init__(self, size=3, win_len=3):
#         self.size = size
#         self.win_len = win_len
#         self.board = [[' ' for _ in range(size)] for _ in range(size)]
#         self.current_player = 'X'
#         self.move_history = []

#     def legal_moves(self):
#         return [(r, c) for r in range(self.size)
#                 for c in range(self.size) if self.board[r][c] == ' ']

#     def apply_move(self, move):
#         r, c = move
#         if self.board[r][c] != ' ':
#             return False  # illegal move
#         self.board[r][c] = self.current_player
#         self.move_history.append((self.current_player, move))
#         self.current_player = 'O' if self.current_player == 'X' else 'X'
#         return True

#     def check_winner(self):
#         lines = []

#         for i in range(self.size):
#             lines.append(self.board[i])
#             lines.append([self.board[r][i] for r in range(self.size)])

#         for r in range(self.size):
#             for c in range(self.size):
#                 diag1, diag2 = [], []
#                 for k in range(self.win_len):
#                     if r+k < self.size and c+k < self.size:
#                         diag1.append(self.board[r+k][c+k])
#                     if r+k < self.size and c-k >= 0:
#                         diag2.append(self.board[r+k][c-k])
#                 if len(diag1) == self.win_len:
#                     lines.append(diag1)
#                 if len(diag2) == self.win_len:
#                     lines.append(diag2)

#         for line in lines:
#             if len(line) >= self.win_len:
#                 for i in range(len(line) - self.win_len + 1):
#                     segment = line[i:i+self.win_len]
#                     if segment.count(segment[0]) == self.win_len and segment[0] != ' ':
#                         return segment[0]
#         return None

#     def is_draw(self):
#         return all(self.board[r][c] != ' '
#                    for r in range(self.size)
#                    for c in range(self.size))


# # ===============================
# # Hybrid Adaptive AI
# # ===============================
# class AdaptiveTTTAI:
#     def __init__(self, symbol):
#         self.symbol = symbol
#         self.opponent = 'O' if symbol == 'X' else 'X'
#         self.state_memory = defaultdict(int)
#         self.random_bias = 0.1

#     def evaluate(self, game):
#         winner = game.check_winner()
#         if winner == self.symbol:
#             return 100
#         if winner == self.opponent:
#             return -100

#         score = 0
#         for r in range(game.size):
#             for c in range(game.size):
#                 if game.board[r][c] == self.symbol:
#                     score += 1
#                 elif game.board[r][c] == self.opponent:
#                     score -= 1
#         return score

#     def heuristic_search(self, game, depth, alpha, beta, maximizing):
#         key = tuple(tuple(row) for row in game.board)
#         self.state_memory[key] += 1

#         if depth == 0 or game.check_winner() or game.is_draw():
#             return self.evaluate(game)

#         moves = game.legal_moves()
#         random.shuffle(moves)

#         if maximizing:
#             value = -math.inf
#             for move in moves:
#                 g2 = self.clone_game(game)
#                 g2.apply_move(move)
#                 value = max(value, self.heuristic_search(g2, depth-1, alpha, beta, False))
#                 alpha = max(alpha, value)
#                 if beta <= alpha:
#                     break
#             return value
#         else:
#             value = math.inf
#             for move in moves:
#                 g2 = self.clone_game(game)
#                 g2.apply_move(move)
#                 value = min(value, self.heuristic_search(g2, depth-1, alpha, beta, True))
#                 beta = min(beta, value)
#                 if beta <= alpha:
#                     break
#             return value

#     def choose_move(self, game):
#         best_score = -math.inf
#         best_move = None

#         for move in game.legal_moves():
#             g2 = self.clone_game(game)
#             g2.apply_move(move)
#             score = self.heuristic_search(
#                 g2,
#                 depth=max(2, game.size - 1),
#                 alpha=-math.inf,
#                 beta=math.inf,
#                 maximizing=False
#             )

#             if random.random() < self.random_bias:
#                 score -= random.randint(1, 5)

#             if score > best_score:
#                 best_score = score
#                 best_move = move

#         if self.detect_optimal_trap():
#             return random.choice(game.legal_moves())

#         return best_move

#     def detect_optimal_trap(self):
#         frequent_states = [v for v in self.state_memory.values() if v > 3]
#         if frequent_states:
#             self.random_bias = min(0.5, self.random_bias + 0.05)
#             return True
#         return False

#     @staticmethod
#     def clone_game(game):
#         g = DynamicTicTacToe(game.size, game.win_len)
#         g.board = [row[:] for row in game.board]
#         g.current_player = game.current_player
#         return g


# # ===============================
# # Simulation with Rule Mutation
# # ===============================
# def run_simulation():
#     game = DynamicTicTacToe(size=3, win_len=3)
#     ai = AdaptiveTTTAI('X')

#     for turn in range(30):
#         if turn == 10:
#             game.size = 4
#             game.win_len = 3
#             game.board = [[' ' for _ in range(4)] for _ in range(4)]
#         if turn == 20:
#             game.win_len = 4

#         if game.current_player == 'X':
#             move = ai.choose_move(game)
#             game.apply_move(move)
#         else:
#             moves = game.legal_moves()
#             if random.random() < 0.3:
#                 move = (random.randint(0, game.size-1), random.randint(0, game.size-1))
#             else:
#                 move = random.choice(moves)
#             game.apply_move(move)

#         if game.check_winner() or game.is_draw():
#             break

#     return game.check_winner()


# if __name__ == "__main__":
#     outcomes = {"X": 0, "O": 0, None: 0}
#     for _ in range(20):
#         outcomes[run_simulation()] += 1
#     print(outcomes)

# import random
# import math
# from collections import defaultdict

# # ======================================================
# # Cloud Resource Allocation as Dynamic CSP (Local Search)
# # ======================================================

# # ------------------------------
# # Resource & Service Definitions
# # ------------------------------
# class ResourcePool:
#     def __init__(self, vms, storage, bandwidth):
#         self.total = {
#             "vm": vms,
#             "storage": storage,
#             "bandwidth": bandwidth
#         }

# class Service:
#     def __init__(self, name, req_vm, req_storage, req_bw, priority=1):
#         self.name = name
#         self.req = {
#             "vm": req_vm,
#             "storage": req_storage,
#             "bandwidth": req_bw
#         }
#         self.priority = priority


# # ------------------------------
# # CSP Allocation Engine
# # ------------------------------
# class AllocationEngine:
#     def __init__(self, resource_pool):
#         self.pool = resource_pool
#         self.services = {}
#         self.allocation = {}
#         self.constraints = []
#         self.best_allocation = None
#         self.best_penalty = math.inf

#     # Dynamic service management
#     def add_service(self, service):
#         self.services[service.name] = service
#         self.allocation[service.name] = {
#             "vm": random.randint(0, service.req["vm"]),
#             "storage": random.randint(0, service.req["storage"]),
#             "bandwidth": random.randint(0, service.req["bandwidth"])
#         }

#     def remove_service(self, name):
#         if name in self.services:
#             del self.services[name]
#             del self.allocation[name]

#     # Dynamic constraint handling
#     def add_constraint(self, constraint_fn, weight=1):
#         self.constraints.append((constraint_fn, weight))

#     def remove_constraint(self, constraint_fn):
#         self.constraints = [c for c in self.constraints if c[0] != constraint_fn]

#     # ------------------------------
#     # Penalty Evaluation Function
#     # ------------------------------
#     def penalty(self):
#         penalty = 0
#         used = defaultdict(int)

#         # Resource overuse penalty
#         for svc, alloc in self.allocation.items():
#             for r in alloc:
#                 used[r] += alloc[r]

#         for r in used:
#             excess = max(0, used[r] - self.pool.total[r])
#             penalty += excess * 10

#         # Service under-allocation penalty
#         for svc in self.services.values():
#             alloc = self.allocation[svc.name]
#             for r in alloc:
#                 deficit = max(0, svc.req[r] - alloc[r])
#                 penalty += deficit * svc.priority * 5

#         # Soft constraints
#         for constraint_fn, weight in self.constraints:
#             penalty += constraint_fn(self.allocation) * weight

#         return penalty

#     # ------------------------------
#     # Local Search (Hill Climbing + Noise)
#     # ------------------------------
#     def improve(self, steps=100):
#         for _ in range(steps):
#             svc = random.choice(list(self.services.keys()))
#             r = random.choice(["vm", "storage", "bandwidth"])
#             old_val = self.allocation[svc][r]

#             # Local random mutation
#             self.allocation[svc][r] = max(
#                 0,
#                 old_val + random.choice([-1, 1])
#             )

#             p = self.penalty()

#             if p < self.best_penalty:
#                 self.best_penalty = p
#                 self.best_allocation = {
#                     s: self.allocation[s].copy()
#                     for s in self.allocation
#                 }
#             else:
#                 # Accept worse move with small probability
#                 if random.random() > 0.1:
#                     self.allocation[svc][r] = old_val

#     def run_continuously(self, iterations=20):
#         for _ in range(iterations):
#             self.improve(steps=50)

#     def current_state(self):
#         return self.allocation, self.penalty()

#     def best_state(self):
#         return self.best_allocation, self.best_penalty


# # ------------------------------
# # Example Soft Constraints
# # ------------------------------
# def balance_vm(allocation):
#     values = [v["vm"] for v in allocation.values()]
#     return max(values) - min(values) if values else 0

# def avoid_zero_bw(allocation):
#     return sum(1 for v in allocation.values() if v["bandwidth"] == 0)


# # ------------------------------
# # Simulation
# # ------------------------------
# if __name__ == "__main__":
#     pool = ResourcePool(vms=10, storage=20, bandwidth=15)
#     engine = AllocationEngine(pool)

#     # Add services dynamically
#     engine.add_service(Service("Auth", 3, 5, 2, priority=3))
#     engine.add_service(Service("DB", 4, 8, 4, priority=5))
#     engine.add_service(Service("Cache", 2, 3, 2, priority=2))
#     engine.add_service(Service("Analytics", 5, 7, 4, priority=1))

#     # Add soft constraints
#     engine.add_constraint(balance_vm, weight=2)
#     engine.add_constraint(avoid_zero_bw, weight=4)

#     # Continuous optimization
#     for cycle in range(5):
#         engine.run_continuously(iterations=10)

#         # Dynamic change: failure / scaling event
#         if cycle == 2:
#             engine.pool.total["vm"] -= 2
#         if cycle == 3:
#             engine.remove_service("Cache")

#     print("Final Allocation:")
#     alloc, penalty = engine.current_state()
#     print(alloc)
#     print("\nBest Partial Solution Found:")
#     best_alloc, best_penalty = engine.best_state()
#     print(best_alloc)
#     print("Penalty:", best_penalty)


# import heapq
# import random
# import math
# from collections import defaultdict

# # ============================================================
# # INTEGRATED AUTONOMOUS AGENT SYSTEM (NLP + CSP + A* + MINIMAX)
# # ============================================================

# # ---------------------------
# # NLP COMMAND INTERPRETER
# # ---------------------------
# class NLPInterpreter:
#     def parse(self, text):
#         text = text.lower()
#         goal = {}
#         if "reach" in text:
#             goal["type"] = "reach"
#         if "avoid" in text:
#             goal["avoid"] = True
#         if "fast" in text:
#             goal["priority"] = "speed"
#         if "safe" in text:
#             goal["priority"] = "safety"
#         if "zone" in text:
#             goal["target"] = text.split()[-1]
#         return goal


# # ---------------------------
# # CSP CONSTRAINT MANAGER
# # ---------------------------
# class ConstraintManager:
#     def __init__(self):
#         self.constraints = []

#     def add(self, fn):
#         self.constraints.append(fn)

#     def valid(self, state):
#         return all(c(state) for c in self.constraints)


# # ---------------------------
# # GRID ENVIRONMENT
# # ---------------------------
# class GridWorld:
#     def __init__(self, size=5):
#         self.size = size
#         self.walls = set()
#         self.goal = (size-1, size-1)

#     def neighbors(self, pos):
#         x, y = pos
#         for dx, dy in [(1,0),(-1,0),(0,1),(0,-1)]:
#             nx, ny = x+dx, y+dy
#             if 0 <= nx < self.size and 0 <= ny < self.size and (nx,ny) not in self.walls:
#                 yield (nx, ny)


# # ---------------------------
# # A* PLANNER
# # ---------------------------
# class AStarPlanner:
#     def heuristic(self, a, b):
#         return abs(a[0]-b[0]) + abs(a[1]-b[1])

#     def plan(self, start, goal, env, csp):
#         open_set = [(0, start)]
#         came_from = {}
#         g = {start: 0}

#         while open_set:
#             _, current = heapq.heappop(open_set)
#             if current == goal:
#                 return self.reconstruct(came_from, current)

#             for n in env.neighbors(current):
#                 if not csp.valid(n):
#                     continue
#                 new_g = g[current] + 1
#                 if n not in g or new_g < g[n]:
#                     g[n] = new_g
#                     f = new_g + self.heuristic(n, goal)
#                     heapq.heappush(open_set, (f, n))
#                     came_from[n] = current
#         return []

#     def reconstruct(self, came_from, current):
#         path = [current]
#         while current in came_from:
#             current = came_from[current]
#             path.append(current)
#         return path[::-1]


# # ---------------------------
# # MINIMAX ADVERSARY
# # ---------------------------
# class MinimaxAdversary:
#     def evaluate(self, agent_pos, adv_pos):
#         return -abs(agent_pos[0]-adv_pos[0]) - abs(agent_pos[1]-adv_pos[1])

#     def best_move(self, adv_pos, agent_pos, env, depth=2):
#         def minimax(pos, depth, maximizing):
#             if depth == 0:
#                 return self.evaluate(agent_pos, pos)
#             moves = list(env.neighbors(pos))
#             if maximizing:
#                 return max(minimax(m, depth-1, False) for m in moves)
#             else:
#                 return min(minimax(m, depth-1, True) for m in moves)
#         moves = list(env.neighbors(adv_pos))
#         return max(moves, key=lambda m: minimax(m, depth, False))


# # ---------------------------
# # INTEGRATED AGENT
# # ---------------------------
# class AutonomousAgent:
#     def __init__(self):
#         self.nlp = NLPInterpreter()
#         self.csp = ConstraintManager()
#         self.planner = AStarPlanner()
#         self.adversary = MinimaxAdversary()
#         self.goal = None

#     def interpret_command(self, text):
#         self.goal = self.nlp.parse(text)

#     def update_constraints(self):
#         if self.goal.get("avoid"):
#             self.csp.add(lambda s: s not in {(2,2)})

#     def act(self, env, agent_pos, adv_pos):
#         path = self.planner.plan(agent_pos, env.goal, env, self.csp)
#         if not path:
#             env.goal = (random.randint(0,4), random.randint(0,4))
#             return agent_pos
#         adv_pos = self.adversary.best_move(adv_pos, agent_pos, env)
#         return path[1] if len(path) > 1 else agent_pos, adv_pos


# # ---------------------------
# # SIMULATION LOOP (NO RESTARTS)
# # ---------------------------
# if __name__ == "__main__":
#     env = GridWorld()
#     agent = AutonomousAgent()
#     agent_pos = (0,0)
#     adv_pos = (4,0)

#     agent.interpret_command("Reach zone safely and avoid center")
#     agent.update_constraints()

#     for step in range(20):
#         agent_pos, adv_pos = agent.act(env, agent_pos, adv_pos)

#         if random.random() < 0.2:
#             agent.interpret_command("Reach zone fast")
#             agent.update_constraints()

#         if agent_pos == env.goal:
#             env.goal = (random.randint(0,4), random.randint(0,4))

#     print("Final Agent Position:", agent_pos)
#     print("Final Adversary Position:", adv_pos)
