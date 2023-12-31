---
title: German Style Guide
---

Diese Datei enthält Anmerkungen für alle, die das Spiel ins Deutsche übersetzen wollen.

---

## Sprache

Deutsch wie in Deutschland üblich (de_DE). Wir verwenden die neue deutsche Rechtschreibung.

## Zusammenfassung

- Anführungszeichen: »Beispieltext«
- Innere Anführungszeichen: ›Beispieltext‹
- Anrede: Grundsätzlich mit »du«, mit Ausnahmen (s.u.)
- Strings wie »the %s« oder »a %s« werden besonders übersetzt (s.u.)

## Anrede

Grundsätzlich duzen sich alle. Auch der Spieler wird geduzt.

Die Idee ist, dass nach der Apokalypse das »Sie« einfach aus der Mode kommt. Sind ja nicht mehr
viele übrig. ;-)

Die förmliche Anrede mit »Sie« wird nur in seltenen Ausnahmefällen benutzt. Diese Ausnahmefälle
sind:

- Alte Dokumente aus der Zeit vor der Apokalypse, wo die förmliche Anrede Sinn ergibt, z.B. alte
  Behördenprotokolle
- Computer, Terminals und die meisten anderen Bedienelemente
- Wenn es sinnvoll erscheint, auch bestimmte NPC-Dialoge, aber das dann bitte unbedingt im Spiel
  testen!

Auf keinen Fall darf völlig grundlos zwischen »du« und »Sie« hin- und hergesprungen werden.

## Blöde Sonderregel für Artikel

Es kommen sehr viele Strings vor, bei dem ein Artikel gefolgt von einem Platzhalter auftaucht. Das
ist problematisch für uns, da deutsche Substantive ein Geschlecht haben.

Zusammenfassung ###############

Steht ein Artikel vor einem Platzhalter, wird er wie folgt übersetzt (naja):

- »the %s« → »%s«
- »a %s« → »1 %s«

Beispiele:

- »You hit the %s!« → »Du triffst %s!«
- »You see a %s.« → »Du siehst 1 %s.«

Ausnahmen sind natürlich erlaubt.

Bestimmter Artikel »the« ########################

Beispiel: »You hit the %s!«.

Problematische Übersetzung:

- »Du triffst das %s!«.

So einfach ist das leider nicht, denn wir wissen ja nicht, welches Geschlecht das Wort für %s hat.

Das funktioniert, wenn %s für »Monster« steht (»das Monster«). Aber wenn %s zu »Spinne« wird, dann
kriegen wir »das Spinne«. Das ist blöd. :-(

Wir haben uns daher angewöhnt, den Artikel einfach ganz wegzulassen. Also als ob %s ein Name wäre.

Also:

- »Du triffst %s!«

Das ist zwar immer noch nicht schön, aber besser als »das Spinne«.

Alternativ hat sich auch der Doppelpunkt bewährt. Also:

- »Du triffst: %s«

Bei kurzen Strings kann das sinnvoll sein, bei langen Strings eher nicht.

Unbestimmter Artikel »a«/»an« #############################

Beispiel: »On the ground you see a %s.«

Problematische Übersetzung: »Auf dem Boden siehst du ein %s.«

Wenn wieder die Spinne kommt, haben wir »ein Spinne«. Das ist doof. :-(

Notlösung: Wir ersetzen einfach den unbestimmten Artikel mit »1«. Also:

- »Auf dem Boden siehst du 1 %s.«

Zugegeben, etwas gefudelt ist das schon. Aber es funktioniert! Irgendwie. :D

Auch hier wäre der Ansatz mit dem Doppelpunkt denkbar, aber nur, wenn es sein muss.

Anmerkung #########

Beachte: All diese Ansätze sind nur Notlösungen!

Eine echte Lösung des Problems kann es eigentlich nur geben, wenn die Art, wie C:DDA diese Strings
aufbaut, grundsätzlich ändert. :-(

## Problemwort: »bionics«

C:DDA verwendet »bionic« als Wort für eine Art Implantat, nicht für ein Konzept wie in Wikipedia
beschrieben (s.u.).

So übersetzen wir es:

- »the bionic« → »das Bionik«
- »the bionics« → »die Bioniken«

»bionic« wird auch manchmal als Adjektiv eingesetzt:

- »bionic« → »bionics«

Aus der englischsprachigen Wikipedia: Bionics (also known as biomimicry, biomimetics,
bio-inspiration, biognosis, and close to bionical creativity engineering) is the application of
biological methods and systems found in nature to the study and design of engineering systems and
modern technology

Aus der deutschsprachigen Wikipedia: Die Bionik (auch Biomimikry, Biomimetik oder Biomimese)
beschäftigt sich mit dem Übertragen von Phänomenen der Natur auf die Technik.
