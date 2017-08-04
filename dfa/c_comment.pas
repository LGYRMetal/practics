{ state 1 }
if the next character is “/” then
    advance the input: { state 2 }
    if the next character is “*” then
        advance the input;{ state 3 }
        done := false;
        while not done do
            while the next input character is not “*” do
                advance the input;
            end while;
            advance the input; { state 4 }
            while the next input character is “*” do
                advance the input;
            end while;
            if the next input character is “/” then
                done := true;
            end if;
            advance the input;
        end while;
        accept; { state 5 }
    else { other processing }
    end if;
else { other processing }
end if;
