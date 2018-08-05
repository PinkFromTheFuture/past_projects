library IEEE;
use IEEE.std_logic_1164.all;

entity clk_div is
	generic (
		FACTOR : integer := 4;
		SIZE : integer := 2
	);
	port (
		clkin  :  in std_logic;
		clkout : out std_logic
	);
end clk_div;

architecture clk_div_rtl of clk_div is

signal counter : integer range 0 to 2 ** SIZE - 1;
signal clock : std_logic;

begin

	counter_up : process(clkin) is
	begin
		if clkin'event and clkin = '1' then
			if counter = FACTOR - 1 then
				counter <= 0;
				clock <= not clock;
			else
				counter <= 1 + counter;
				clock <= clock;
			end if;
		end if;
	end process counter_up;

	clkout <= clock;

end clk_div_rtl;
