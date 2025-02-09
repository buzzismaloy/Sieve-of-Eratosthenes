def sieve_of_eratosthenes(n)
  if n < 2
    puts "\n\nThe N must be >= 2!\n"
    return
  end

  size = (n + 1) / 2
  is_prime = Array.new(size, true)
  print "\nPrime numbers up to #{n}:\n2 "

  (3..Math.sqrt(n).to_i).step(2) do |i|
    if is_prime[i / 2]
      (i * i..n).step(2 * i) { |mult| is_prime[mult / 2] = false }
    end
  end

  (1..size).each do |i|
    print "#{2 * i + 1} " if is_prime[i]
  end

  puts "\n"
end

begin
  print "Enter N:\n> "
  n = Integer(gets.chomp)
  sieve_of_eratosthenes(n)
rescue ArgumentError
  puts "\n\nInvalid input!\n"
end
