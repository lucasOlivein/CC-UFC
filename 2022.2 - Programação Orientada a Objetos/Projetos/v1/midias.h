#include "class.h"

void load_midias(vector<Midia> *midia)
{   
    vector<CD> cds;
    vector<DVD> dvds;
    
    CD c;
    DVD d;;

    

    
    
    c.setArtista("Linkin Park");
    c.setTitulo("Hibrid Theory");
    c.setDuracao(80);
    c.setFaixas({"Papercut", "One Step Closer", "With You", "Points of Authority", "Crawling", "Runaway", "By Myself", "A Place For My Head"});
    c.setLancamento(2000);
    c.setGenero("Rock");
    c.setKeywords();
    cds.push_back(c);
    
    
    
    
    c.setArtista("Linkin Park");
    c.setDuracao(37);
    c.setFaixas({"Foreword", "Don't Stay", "Somewhere I Belong", "Lying from Yoy", "Hit the Floor","Easier to Run", "Faint", "Figure.09", "Breaking the Habit", "From the Inside", "Nobody's Listening", "Session", "Numb"});
    c.setLancamento(2003);
    c.setTitulo("Meteora");
    c.setGenero("Rock");
    c.setKeywords();
    cds.push_back(c);
    
    
    
    c.setArtista("Linkin Park");
    c.setDuracao(37);
    c.setFaixas({"Lost in the Echo", "In My Remains", "Burn It Down", "Lies Greed Misery", "I'll Be Gone", "Castle of Glass", "Victimized", "Roads Untraveled", "Skin to Bone", "Until It Breaks", "Tinfoil", "Powerless"});
    c.setLancamento(2012);
    c.setTitulo("Living Things");
    c.setGenero("Rock");
    c.setKeywords();
    cds.push_back(c);
    

    
    c.setArtista("Three Days Grace");
    c.setTitulo("Human");
    c.setDuracao(40);
    c.setFaixas({"Human Race", "Painkiller", "Fallen Angel", "Landmine", "Tell Me Why", "I Am Machine", "So What", "Car Crash", "Nothing's Fair in Love and War", "One Too Many", "The End Is Not the Answer", "The Real You"});
    c.setLancamento(2015);
    c.setGenero("Alternative");
    c.setKeywords();
    cds.push_back(c);
    

    
    c.setArtista("Three Days Grace");
    c.setTitulo("Outsider");
    c.setDuracao(39);
    c.setFaixas({"Right Left Wrong", "The Mountain", "I Am an Outsider", "Infra-Red", "Nothing to Lose but You", "Me Against You", "Love Me or Leave Me", "Strange Days", "Villain I'm Not", "Chasing the First Time", "The New Real", "The Abyss"});
    c.setLancamento(2018);
    c.setGenero("Alternative");
    c.setKeywords();
    cds.push_back(c);
    

    
    c.setArtista("Three Days Grace");
    c.setTitulo("Explosions");
    c.setDuracao(38);
    c.setFaixas({"So Called Life", "I Am the Weapon", "Neurotic", "Lifetime", "A Scar Is Born", "Souvenirs", "No Tomorrow", "Redemption", "Champion", "Chain of Abuse", "Someone to Talk To", "Explosions",});
    c.setLancamento(2022);
    c.setGenero("Rock");
    c.setKeywords();
    cds.push_back(c);
    

    
    c.setArtista("Three Days Grace");
    c.setTitulo("Life Starts Now");
    c.setDuracao(43);
    c.setFaixas({"Bitter Taste", "Break", "World So Cold", "Lost in You", "The Good Life", "No More", "Last to Know", "Someone Who Cares", "Bully", "Without You", "Goin' Down", "Life Starts Now",});
    c.setLancamento(2009);
    c.setGenero("Alternative");
    c.setKeywords();
    cds.push_back(c);
    

    
    c.setArtista("Guns N' Roses");
    c.setTitulo("Greatest Hits");
    c.setDuracao(79);
    c.setFaixas({"Welcome to the Jungle", "Sweet Child O' Mine","Patience", "Paradise City" ,	"Knockin' On Heaven's Door","Civil War", "You Could Be Mine" ,	"Don't Cry","November Rain","Live And Let Die","Yesterdays", "Ain't It Fun","Since I Don't Have You", "Sympathy for the Devil"});
    c.setLancamento(2004);
    c.setColetania(true);
    c.setGenero("Rock");
    c.setKeywords();
    cds.push_back(c);
    

    
    c.setArtista("Guns N' Roses");
    c.setTitulo("Chinese Democracy");
    c.setDuracao(71);
    c.setFaixas({"Chinese Democracy",	"Shackler's Revenge","Better", "Street of Dreams",	"If the World",	"There Was a Time" ,"Catcher in the Rye", "Scraped", "Riad N' the Bedouins","Sorry","I.R.S." ,	"Madagascar","This I Love","Prostitute" });
    c.setLancamento(2008);
    c.setGenero("Rock");
    c.setKeywords();
    cds.push_back(c);
    

    
    c.setArtista("Imagine Dragons");
    c.setTitulo("Evolve");
    c.setDuracao(39);
    c.setFaixas({	"I Don't Know Why",	"Whatever It Takes","Believer","Walking the Wire","Rise Up" , "I'll Make It Up to You" , "Yesterday","Mouth of the River","Thunder", "Start Over","Dancing in the Dark"});
    c.setLancamento(2017);
    c.setGenero("Rock");
    c.setKeywords();
    cds.push_back(c);
    

    


    
    d.setArtista("Linkin Park");
    d.setLancamento(2003);
    d.setTitulo("Live in Texas");
    d.setFaixas({"Don't Say", "Somewhere I Belong", "Lying from You", "Papercut", "Points of Authority", "Runaway", "Faint", "From the Inside", "P5hng Me A*wy", "Numb", "Crawling", "In the End", "One Step Closer"});
    d.setGenero("Alternative");
    d.setKeywords();
    dvds.push_back(d);
    

    
    d.setArtista("Linkin Park");
    d.setLancamento(2017);
    d.setTitulo("One More Light");
    d.setFaixas({"Talking to Myself", "Burn It Down", "Battle Symphony", "New Divide", "Invisible", "Nobody Can Save Me", "One More Light", "Crawling", "Leave Out All the Rest", "Good Goodbye", "What I've Done", "In the End", "Sharp Edges", "Numb", "Heavy", "Bleed It Out"});
    d.setGenero("Alternative");
    d.setKeywords();
    dvds.push_back(d);
    

    
    d.setArtista("Three Days Grace");
    d.setLancamento(2008);
    d.setTitulo("Live at the Palace");
    d.setFaixas({"Animal I have Become", "Pain", "Just Like You", "Let it Die", "Wake Up", "I Hate Everything About You", "Rooster", "Riot", "Get Out Alive", "Never Too Late", "Scared", "Gone Forever", "Home", "It's All Over"});
    d.setGenero("Alternative");
    d.setKeywords();
    dvds.push_back(d);
    
    
    
    d.setArtista("Linkin Park");
    d.setLancamento(2008);
    d.setTitulo("Road to Revolution");
    d.setFaixas({"From the Inside", "No More Sorrow", "Wake 2.0", "Given Up", "Lying from You", "Hands Held Hight", "Leave Out All the Rest", "Numb", "The Little Things Give You Away", "Breaking the Habit", "Shadow of the Day", "Crawling", "In the End", "Pushing Me Away", "What I've Done", "Numb/Encore", "Jigga What/Faint", "Bleed It Out"});
    d.setGenero("Rock");
    d.setKeywords();
    dvds.push_back(d);
    

    
    
    d.setArtista("Guns N' Roses");
    d.setLancamento(1992);
    d.setTitulo("Use Your Illusion I");
    d.setFaixas({"Nightrain", "Mr. Brownstone", "Live And Let Die", "It's So Easy", "Bad Obsession", "Attitude", "Pretty Tied Up", "Welcome To The Jungle", "Don't Cry", "Double Talki' Jive", "Civel War", "Wild Horses", "Patience", "November Rain"});
    d.setGenero("Rock");
    d.setKeywords();
    dvds.push_back(d);
    

    
    d.setArtista("Guns N' Roses");
    d.setLancamento(1992);
    d.setTitulo("Use Your Illusion II");
    d.setFaixas({"You Could Be Mine", "Drum Solo & Guitar Solo", "Theme From The Godfather", "Sweet Child o' Mine", "So Fine", "Rocket Queen", "Move To The City", "Knockin' on Heaven's Door", "Estranged", "Paradise City"});
    d.setGenero("Rock");
    d.setKeywords();
    dvds.push_back(d);
    

    
    d.setArtista("Artic Monkeys");
    d.setLancamento(2008);
    d.setTitulo("Artic Monkeys Live at the Apollo");
    d.setFaixas({"Brianstorm", "This House Is a Circus", "Teddy Picker", "I Bet You Look Good on the Dancefloor", "Dancing Shoes","From the Ritz to the Rubble", "Fake Tales of San Francisco", "Balaclava","When the Sun Goes Down","Nettles","D Is for Dangerous","Leave Before the Lights Come On","Fluorescent Adolescent", "Still Take You Home", "Da Frame 2R","Plastic Tramp","505", "Do Me a Favour","A Certain Romance", "The View from the Afternoon", "If You Were There, Beware",  " Baby I'm Yours"   });
    d.setGenero("Rock");
    d.setKeywords();
    dvds.push_back(d);
    


    
    d.setArtista("Red Hot Chili Peppers");
    d.setLancamento(1992);
    d.setTitulo("What Hits");
    d.setFaixas({"Higher Ground","Fight Like a Brave","Behind the Sun",  "Me and My Friends", "Backwoods", "True Men Don't Kill Coyotes",	"Fire","Get Up and Jump", "Knock Me Down", "Under the Bridge","Show Me Your Soul", "If You Want Me to Stay", "Hollywood (Africa)", "Jungle Man", "The Brothers Cup","Taste the Pain", "Catholic School Girls Rules","Johnny, Kick a Hole in the Sky"     });
    d.setGenero("Rock");
    d.setKeywords();
    dvds.push_back(d);
    


    
    d.setArtista("Red Hot Chili Peppers");
    d.setLancamento(2001);
    d.setTitulo("Off the Map");
    d.setFaixas({"Around the World", "Give It Away", "Usually Just A T Shirt #3","Scar Tissue",  "Suck my Kiss", "If You Have to Ask", "Subterranean Homesick Blues","Otherside", "Blackeyed Blonde", "Pea","Blood Sugar Sex Magik", "Easily", "What Is Soul?", "(The Jam)",  "Fire", "Californication", "Right On Time","Under the Bridge",  "Me and My Friends" });
    d.setGenero("Alternative");
    d.setKeywords();
    dvds.push_back(d);
    

    
    d.setArtista("Red Hot Chili Peppers");
    d.setLancamento(2003);
    d.setTitulo("Live at Slane Castle");
    d.setFaixas({"By The Way", "Scar Tissue", "Around the World","Universally Speaking", "Parallel Universe","The Zephyr Song","Throw Away Your Television", "Havana Affair",  "Otherside", "Purple Stain","Don't Forget Me", "Right on Time", "Can't Stop", "Venice Queen", "Give It Away","Californication", "Under the Bridge", "Power of Equality", "Final Credits" });
    d.setGenero("Rock");
    d.setKeywords();
    dvds.push_back(d);
    

    

    
    d.setArtista("Imagine Dragons");
    d.setLancamento(2015);
    d.setTitulo("Night Visions Live");
    d.setFaixas({"Radioactive","Hear Me","On Top of the World","Round and Round", "Amsterdam",  "Tip Toe", "Cha-Ching","Rocks", "Demons", "Underdog","It's Time","Radioactive", 	"Demons"     });
    d.setGenero("Rock");
    d.setKeywords();
    dvds.push_back(d);
    
    
    
    for(int i=0; i< dvds.size(); i++){
        midia->push_back(dvds[i]);
        
    }
    for (int i = 0; i < cds.size(); i++){
        midia->push_back(cds[i]);
        
        
    }
    
}