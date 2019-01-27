function numtobi(a:integer):string;
var t:integer;
    s:string;
begin
  s:='';
  while a>0 do begin
    s:=chr((a mod 2)+ord('0'))+s;
    a:=a div 2;
   end;
  numtobi:=s;
end;
var
  s,sn: string;
  i, t, k,l: integer;
begin
  writeln('¬ведите сообщение:');
  readln(s);
  sn:='';i:=0;
  for t:=1 to length(s) do begin
    sn:=sn+numtobi(ord(s[t]));
    i:=i+ord(s[t]);
  end;
  k:=0;
  for l:= 1 to i mod 255 do begin
    sn:=sn+sn[1];delete(sn,1,1);
    for t:=1 to length(s) do begin
      k:=(k*ord(s[t])+ord(s[length(s)-t+1])) mod 1024;
    end;
  end; 
  writeln('’еш-сумма = ', k);
end.