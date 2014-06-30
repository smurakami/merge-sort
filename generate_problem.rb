num = 10
size = 40
f = open("problem.txt", "w")

num.times do
  a = (0...size).to_a.shuffle
  f.puts a.join(' ')
end
