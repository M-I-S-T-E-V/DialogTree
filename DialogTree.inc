/* 

    M I S T E V

*/

// ALS prefix DLG / DLGDTR


#if defined INC_DIALOG_TREE
    #endinput
#endif
#define INC_DIALOG_TREE


#tryinclude <a_samp>
#tryinclude <open.mp>


#if !defined Dialog
    #define Dialog: #
#endif


//#define DIALOG_TREE_LITE


//#define DIALOG_TREE_PARENT


//#define DIALOG_TREE_WITHOUT_ARRAY


//#define DIALOG_TREE_WITHOUT_BOOK


//#define DIALOG_BUTTON_ESC


//#define DIALOG_TREE_EDITOR


#if defined DIALOG_TREE_LITE
    #if defined DIALOG_TREE_EDITOR
        #undef DIALOG_TREE_EDITOR
    #endif
#endif


#if defined DIALOG_BUTTON_ESC
    #if !defined _INC_open_mp
        #error "{ff0000}[DialogTree]{ffffff} Detecting the ESC key is only possible in Open MP"
    #endif
#endif


#if !defined DIALOG_ID
    #define DIALOG_ID (32767)
#endif


#if !defined MAX_DIALOG_ID
    #define MAX_DIALOG_ID (1000)
#endif


#if !defined INVALID_DIALOG_ID
    #define INVALID_DIALOG_ID (-1)
#endif


#if !defined MAX_DIALOG_COLOR
    #define MAX_DIALOG_COLOR (8)
#endif


#if !defined SIZE_DIALOG_COLOR
    #define SIZE_DIALOG_COLOR (MAX_DIALOG_COLOR+1)
#endif


#if defined MAX_DIALOG_NAME
    #undef MAX_DIALOG_NAME
#endif
#define MAX_DIALOG_NAME (31)


#if defined SIZE_DIALOG_NAME
    #undef SIZE_DIALOG_NAME
#endif
#define SIZE_DIALOG_NAME (MAX_DIALOG_NAME+1)


#if !defined MAX_DIALOG_CAPTION
    #define MAX_DIALOG_CAPTION (64)
#endif


#if defined SIZE_DIALOG_CAPTION
    #undef SIZE_DIALOG_CAPTION
#endif
#define SIZE_DIALOG_CAPTION (MAX_DIALOG_CAPTION+1)


#if !defined MAX_DIALOG_INFO
    #define MAX_DIALOG_INFO (1024)
#endif


#if defined SIZE_DIALOG_INFO
    #undef SIZE_DIALOG_INFO
#endif
#define SIZE_DIALOG_INFO (MAX_DIALOG_INFO+1)


#if !defined MAX_DIALOG_BUTTON
    #define MAX_DIALOG_BUTTON (28)
#endif


#if defined SIZE_DIALOG_BUTTON
    #undef SIZE_DIALOG_BUTTON
#endif
#define SIZE_DIALOG_BUTTON (MAX_DIALOG_BUTTON+1)


#if !defined MAX_DIALOG_INPUTTEXT
    #define MAX_DIALOG_INPUTTEXT (128)
#endif


#if defined SIZE_DIALOG_INPUTTEXT
    #undef SIZE_DIALOG_INPUTTEXT
#endif
#define SIZE_DIALOG_INPUTTEXT (MAX_DIALOG_INPUTTEXT+1)


#if !defined DIALOG_TREE_WITHOUT_BOOK

    #if !defined MAX_DIALOG_ROW
        #define MAX_DIALOG_ROW (100)
    #endif


    #if defined DLG_STYLE_BOOK
        #undef DLG_STYLE_BOOK
    #endif
    #define DLG_STYLE_BOOK (10)


    #if defined DIALOG_STYLE_BOOK
        #undef DIALOG_STYLE_BOOK
    #endif
    #define DIALOG_STYLE_BOOK<%1> (DLG_STYLE_BOOK*%1)


    #if defined DLG_STYLE_TABBOOK
        #undef DLG_STYLE_TABBOOK
    #endif
    #define DLG_STYLE_TABBOOK (10_000)


    #if defined DIALOG_STYLE_TABBOOK
        #undef DIALOG_STYLE_TABBOOK
    #endif
    #define DIALOG_STYLE_TABBOOK<%1> (DLG_STYLE_TABBOOK*%1)


    #if defined DLG_STYLE_TABBOOK_HEADERS
        #undef DLG_STYLE_TABBOOK_HEADERS
    #endif
    #define DLG_STYLE_TABBOOK_HEADERS (10_000_000)


    #if defined DIALOG_STYLE_TABBOOK_HEADERS
        #undef DIALOG_STYLE_TABBOOK_HEADERS
    #endif
    #define DIALOG_STYLE_TABBOOK_HEADERS<%1> (DLG_STYLE_TABBOOK_HEADERS*%1)


    #if !defined DIALOG_ARROW_LEFT
        #define DIALOG_ARROW_LEFT ("<")
    #endif


    #if !defined DIALOG_ARROW_RIGHT
        #define DIALOG_ARROW_RIGHT (">")
    #endif

#endif


#if defined OnDialog
    #undef OnDialog
#endif

#if defined DIALOG_TREE_PARENT
    #define OnDialog:<%0>%1(playerid) forward %1(playerid, dlg_response, dlg_listitem, dlg_inputtext[]); public %1(playerid, dlg_response, dlg_listitem, dlg_inputtext[])
#else
    #define OnDialog:%1(playerid) forward %1(playerid, dlg_response, dlg_listitem, dlg_inputtext[]); public %1(playerid, dlg_response, dlg_listitem, dlg_inputtext[])
#endif


#if defined DialogFunction
    #undef DialogFunction
#endif
#define DialogFunction:%1(playerid) forward %1(playerid); public %1(playerid)


#if defined ClosePlayerDialog
    #undef ClosePlayerDialog
#endif
#define ClosePlayerDialog(%1) DLG_ClosePlayerDialog(%1)


#if defined IsDialogResponseLeft
    #undef IsDialogResponseLeft
#endif
#define IsDialogResponseLeft() (dlg_response == 1)


#if defined IsDialogResponseRight
    #undef IsDialogResponseRight
#endif
#define IsDialogResponseRight() (dlg_response == 0)


#if defined DIALOG_BUTTON_ESC

    #if defined IsDialogResponseESC
        #undef IsDialogResponseESC
    #endif
    #define IsDialogResponseESC() (dlg_response == 2)

#endif


#if defined GetDialogListitem
    #undef GetDialogListitem
#endif
#define GetDialogListitem() (dlg_listitem)


#if defined GetDialogInputtext
    #undef GetDialogInputtext
#endif
#define GetDialogInputtext() (dlg_inputtext)


forward OnPlayerDialogReceived(playerid, const dialog[]);


static stock dtreeFunction[MAX_DIALOG_ID][SIZE_DIALOG_NAME];

#if !defined DIALOG_TREE_LITE

    static stock dtreeReferral[MAX_DIALOG_ID];

#endif

static stock dtreeDefaultDialogStyle[MAX_DIALOG_ID],
             dtreeDefaultDialogCaption[MAX_DIALOG_ID][SIZE_DIALOG_CAPTION],
             dtreeDefaultDialogInfo[MAX_DIALOG_ID][SIZE_DIALOG_INFO],
             dtreeDefaultDialogLeft[MAX_DIALOG_ID][SIZE_DIALOG_BUTTON],
             dtreeDefaultDialogRight[MAX_DIALOG_ID][SIZE_DIALOG_BUTTON];

static stock dtreeFunctionDialogStyle[MAX_DIALOG_ID][SIZE_DIALOG_NAME],
             dtreeFunctionDialogCaption[MAX_DIALOG_ID][SIZE_DIALOG_NAME],
             dtreeFunctionDialogInfo[MAX_DIALOG_ID][SIZE_DIALOG_NAME],
             dtreeFunctionDialogLeft[MAX_DIALOG_ID][SIZE_DIALOG_NAME],
             dtreeFunctionDialogRight[MAX_DIALOG_ID][SIZE_DIALOG_NAME];

#if !defined DIALOG_TREE_WITHOUT_BOOK

    static stock dtreeDialogRow[MAX_DIALOG_ID];

#endif

static stock dtreeDialogColorCaption[MAX_DIALOG_ID][SIZE_DIALOG_COLOR],
             dtreeDialogColorInfo[MAX_DIALOG_ID][SIZE_DIALOG_COLOR],
             dtreeDialogColorLeft[MAX_DIALOG_ID][SIZE_DIALOG_COLOR],
             dtreeDialogColorRight[MAX_DIALOG_ID][SIZE_DIALOG_COLOR];

static stock dtreePlayerDialogid[MAX_PLAYERS],

             dtreePlayerDialogStyle[MAX_PLAYERS],
             dtreePlayerDialogCaption[MAX_PLAYERS][SIZE_DIALOG_CAPTION],
             dtreePlayerDialogInfo[MAX_PLAYERS][SIZE_DIALOG_INFO],
             dtreePlayerDialogLeft[MAX_PLAYERS][SIZE_DIALOG_BUTTON],
             dtreePlayerDialogRight[MAX_PLAYERS][SIZE_DIALOG_BUTTON];

#if !defined DIALOG_TREE_WITHOUT_BOOK

    static stock dtreePlayerRow[MAX_PLAYERS],
                 dtreePlayerPage[MAX_PLAYERS];

#endif


#if defined DIALOG_BUTTON_ESC

    stock DLG_ShowPlayerDialog(playerid, dialogid, style, caption[], info[], button1[], button2[]="")
    {
        if(dialogid == DIALOG_ID)
            SelectTextDraw(playerid, 0x00000000);


        return ShowPlayerDialog(playerid, dialogid, style, caption, info, button1, button2);
    }

    #if defined _ALS_ShowPlayerDialog
        #undef ShowPlayerDialog
    #else
        #define _ALS_ShowPlayerDialog
    #endif
    #define ShowPlayerDialog DLG_ShowPlayerDialog


    public OnPlayerClickTextDraw(playerid, Text:clickedid)
    {
        if(clickedid == Text:INVALID_PLAYER_ID)
        {
            if(IsPlayerOpenDialog(playerid))
                CallLocalFunction("OnDialogResponse", "iiii", playerid, DIALOG_ID, 2, -1);
        }


        #if defined DLG_OnPlayerClickTextDraw
            return DLG_OnPlayerClickTextDraw(playerid, clickedid);
        #else
            return 1;
        #endif
    }

    #if defined _ALS_OnPlayerClickTextDraw
        #undef OnPlayerClickTextDraw
    #else
        #define _ALS_OnPlayerClickTextDraw
    #endif
    #define OnPlayerClickTextDraw DLG_OnPlayerClickTextDraw
    #if defined DLG_OnPlayerClickTextDraw
        forward DLG_OnPlayerClickTextDraw(playerid, Text:clickedid);
    #endif

#endif


public OnGameModeInit()
{
    for(new i = 0; i < MAX_DIALOG_ID; i++)
    {
        dtreeDefaultDialogStyle[i] = INVALID_DIALOG_ID;

        #if !defined DIALOG_TREE_LITE
        
            dtreeReferral[i] = INVALID_DIALOG_ID;

        #endif
    }


    #if defined DLG_OnGameModeInit
        return DLG_OnGameModeInit();
    #else
        return 1;
    #endif
}

#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif
#define OnGameModeInit DLG_OnGameModeInit
#if defined DLG_OnGameModeInit
    forward DLG_OnGameModeInit();
#endif


public OnPlayerConnect(playerid)
{
    DLG_ClosePlayerDialog(playerid);


    #if defined DLG_OnPlayerConnect
        return DLG_OnPlayerConnect(playerid);
    #else
        return 1;
    #endif
}

#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect DLG_OnPlayerConnect
#if defined DLG_OnPlayerConnect
    forward DLG_OnPlayerConnect(playerid);
#endif


#if defined _INC_open_mp
    #pragma warning disable 234
#endif


public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == DIALOG_ID)
    {
        if(dtreePlayerDialogid[playerid] != INVALID_DIALOG_ID)
        {
            #if !defined DIALOG_TREE_WITHOUT_BOOK

                if(dtreePlayerPage[playerid] != INVALID_DIALOG_ID)
                {
                    if(!strcmp(inputtext, DIALOG_ARROW_LEFT))
                    {
                        dtreePlayerPage[playerid]--;

                        return OpenPlayerDialog(playerid, "", dtreePlayerDialogStyle[playerid], dtreePlayerDialogCaption[playerid], dtreePlayerDialogInfo[playerid], dtreePlayerDialogLeft[playerid], dtreePlayerDialogRight[playerid]);
                    }

                    else if(!strcmp(inputtext, DIALOG_ARROW_RIGHT))
                    {
                        dtreePlayerPage[playerid]++;

                        return OpenPlayerDialog(playerid, "", dtreePlayerDialogStyle[playerid], dtreePlayerDialogCaption[playerid], dtreePlayerDialogInfo[playerid], dtreePlayerDialogLeft[playerid], dtreePlayerDialogRight[playerid]);
                    }
                }

            #endif


            dtreePlayerDialogStyle[playerid] = INVALID_DIALOG_ID;
            dtreePlayerDialogCaption[playerid][0] = EOS;
            dtreePlayerDialogInfo[playerid][0] = EOS;
            dtreePlayerDialogLeft[playerid][0] = EOS;
            dtreePlayerDialogRight[playerid][0] = EOS;


            #if defined _INC_open_mp

                if(inputtext[0] == EOS)
                    CallLocalFunction(dtreeFunction[dtreePlayerDialogid[playerid]], "iiis", playerid, response, listitem, '\0');
                else
                    CallLocalFunction(dtreeFunction[dtreePlayerDialogid[playerid]], "iiis", playerid, response, listitem, inputtext);

            #else

                if(inputtext[0] == EOS)
                    CallLocalFunction(dtreeFunction[dtreePlayerDialogid[playerid]], "iii", playerid, response, listitem);
                else
                    CallLocalFunction(dtreeFunction[dtreePlayerDialogid[playerid]], "iiis", playerid, response, listitem, inputtext);

            #endif
        }

        #if defined DIALOG_TREE_EDITOR

            else
                DialogTreeEditor(playerid);

        #endif
    }


    #if defined DLG_OnDialogResponse
        return DLG_OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
    #else
        return 1;
    #endif
}

#if defined _ALS_OnDialogResponse
    #undef OnDialogResponse
#else
    #define _ALS_OnDialogResponse
#endif
#define OnDialogResponse DLG_OnDialogResponse
#if defined DLG_OnDialogResponse
    forward DLG_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
#endif


#if defined _INC_open_mp
    #pragma warning enable 234
#endif


static stock GetDialogID(const dialog[])
{
    if(dialog[0] == EOS)
        return INVALID_DIALOG_ID;


    new result = INVALID_DIALOG_ID;

    for(new i = 0; i < MAX_DIALOG_ID; i++)
    {
        if(dtreeFunction[i][0] == EOS)
            continue;


        if(strcmp(dtreeFunction[i], dialog))
            continue;


        result = i;

        break;
    }


    return result;
}


#if defined DIALOG_TREE_LITE

    static stock GetDialogFree()
    {
        new result = INVALID_DIALOG_ID;

        for(new i = 0; i < MAX_DIALOG_ID; i++)
        {
            if(dtreeFunction[i][0] != EOS)
                continue;

            result = i;

            break;
        }


        return result;
    }

#endif


static stock UpdateDialogColor(const input[], const hex[], string[], size)
{
    string[0] = EOS;


    if(strlen(input) >= 7 && hex[0] != EOS)
    {
        if(input[0] != '{' && input[7] != '}')
        {
            strcat(string, "{", size);
            strcat(string, hex, size);
            strcat(string, "}", size);
            
            strcat(string, input, size);
        }
        else
            strcat(string, input, size);
    }
    else
        strcat(string, input, size);


    return 1;
}


#if !defined DIALOG_TREE_WITHOUT_BOOK

    static stock CheckDialogStyle(playerid, dialogid, style)
    {
        if(style == INVALID_DIALOG_ID && dtreeDefaultDialogStyle[dialogid] != INVALID_DIALOG_ID)
            style = dtreeDefaultDialogStyle[dialogid];


        if(style < DLG_STYLE_BOOK)
        {
            dtreePlayerRow[playerid] = 0;
            dtreeDialogRow[dialogid] = 0;
        }

        else if(DLG_STYLE_BOOK <= style && style < DLG_STYLE_TABBOOK)
        {
            dtreePlayerRow[playerid] = (style/DLG_STYLE_BOOK);
            dtreeDialogRow[dialogid] = (style/DLG_STYLE_BOOK);
        }

        else if(DLG_STYLE_TABBOOK <= style && style < DLG_STYLE_TABBOOK_HEADERS)
        {
            dtreePlayerRow[playerid] = (style/DLG_STYLE_TABBOOK);
            dtreeDialogRow[dialogid] = (style/DLG_STYLE_TABBOOK);
        }

        else if(DLG_STYLE_TABBOOK_HEADERS <= style)
        {
            dtreePlayerRow[playerid] = (style/DLG_STYLE_TABBOOK_HEADERS);
            dtreeDialogRow[dialogid] = (style/DLG_STYLE_TABBOOK_HEADERS);
        }


        if(dtreePlayerRow[playerid] > MAX_DIALOG_ROW)
        {
            dtreePlayerRow[playerid] = MAX_DIALOG_ROW;
            dtreeDialogRow[dialogid] = MAX_DIALOG_ROW;
        }


        return dtreeDialogRow[dialogid];
    }


    static stock GetDialogPage(playerid, dialogid, style, const info[], string[])
    {
        new offset;

        if(DLG_STYLE_TABBOOK_HEADERS <= style)
            offset = 1;
        else
            offset = 0;


        new indexStart[(MAX_DIALOG_ROW+1)],
            indexEnd[(MAX_DIALOG_ROW+1)],

            len = strlen(info),
            row;

        for(new i = 0, s = 1, e; i < len; i++)
        {
            if(info[i] == '\n')
            {
                if(s < (MAX_DIALOG_ROW+offset))
                    indexStart[s] = (i+1);

                s++;


                if(e < (MAX_DIALOG_ROW+offset))
                    indexEnd[e] = i;

                e++;


                if(row >= (MAX_DIALOG_ROW-1+offset))
                    break;

                row++;
            }
        }


        for(new i = 0, l; i < (MAX_DIALOG_ROW+1); i++)
        {
            if(indexEnd[i] > l)
                l = indexEnd[i];
            else
                indexEnd[i] = l;
        }


        len = indexEnd[row];


        row++;

        if(row >= (MAX_DIALOG_ROW+offset))
            row = (MAX_DIALOG_ROW-1+offset);


        for(new i = 0; i < (MAX_DIALOG_ROW+1); i++)
        {
            if(indexEnd[i])
                continue;

            indexEnd[i] = indexEnd[row];
        }


        new maxRow = (dtreePlayerRow[playerid]) ? (dtreePlayerRow[playerid]) : (dtreeDialogRow[dialogid]);

        
        if(row > maxRow)
        {
            new text[SIZE_DIALOG_INFO],

                s = (maxRow*dtreePlayerPage[playerid]),
                e = ((maxRow*dtreePlayerPage[playerid])+maxRow-1);

            strmid(text, info, indexStart[(s+offset)], indexEnd[(e+offset)]);


            if(offset)
            {
                new caption[SIZE_DIALOG_INFO/4];

                strmid(caption, dtreePlayerDialogInfo[playerid], indexStart[0], indexEnd[0]);

                strcat(string, caption, MAX_DIALOG_INFO);
                strcat(string, "\n", MAX_DIALOG_INFO);
            }


            strcat(string, text, MAX_DIALOG_INFO);


            if(dtreePlayerPage[playerid] > 0)
            {
                strcat(string, "\n", MAX_DIALOG_INFO);
                strcat(string, DIALOG_ARROW_LEFT, MAX_DIALOG_INFO);
            }


            if(indexEnd[(e+offset)] < len)
            {
                strcat(string, "\n", MAX_DIALOG_INFO);
                strcat(string, DIALOG_ARROW_RIGHT, MAX_DIALOG_INFO);
            }
        }
        else
            strmid(string, dtreePlayerDialogInfo[playerid], 0, len, MAX_DIALOG_INFO);


        return 1;
    }

#endif


#if !defined DIALOG_TREE_LITE

    stock CreateDialog(const parent[], const dialog[]="")
    {
        if(parent[0] == EOS)
            return 0;

        
        new function[SIZE_DIALOG_NAME];

        if(dialog[0] == EOS)
            strcat(function, parent, SIZE_DIALOG_NAME);
        else
            strcat(function, dialog, SIZE_DIALOG_NAME);


        if(GetDialogID(function) != INVALID_DIALOG_ID)
        {
            printf("\n[DialogTree] Dialog already created (%s)", function);

            return 0;
        }


        new dialogid = INVALID_DIALOG_ID;

        for(new i = 0; i < MAX_DIALOG_ID; i++)
        {
            if(dtreeFunction[i][0] == EOS)
            {
                dialogid = i;

                break;
            }
        }

        if(dialogid == INVALID_DIALOG_ID)
        {
            printf("\n[DialogTree] Attempted to write array element at index %i in array of size %i (MAX_DIALOG_ID)", (MAX_DIALOG_ID+1), MAX_DIALOG_ID);

            return 0;
        }


        dtreeReferral[dialogid] = GetDialogID(parent);

        strcat((dtreeFunction[dialogid][0] = EOS, dtreeFunction[dialogid]), function, MAX_DIALOG_NAME);


        return 1;
    }

#endif


stock SetDefaultDialogStyle(const dialog[], style)
{
    if(style < 0)
        return 0;


    new dialogid = GetDialogID(dialog);

    if(dialogid == INVALID_DIALOG_ID)
    #if defined DIALOG_TREE_LITE
    {
        dialogid = GetDialogFree();

        if(dialogid == INVALID_DIALOG_ID)
            return 0;


        strcat((dtreeFunction[dialogid][0] = EOS, dtreeFunction[dialogid]), dialog, MAX_DIALOG_NAME);
    }
    #else
        return 0;
    #endif


    return dtreeDefaultDialogStyle[dialogid] = style;
}

stock SetDefaultDialogCaption(const dialog[], const caption[], const color[]="")
{
    if(caption[0] == EOS)
        return 0;


    new dialogid = GetDialogID(dialog);
    
    if(dialogid == INVALID_DIALOG_ID)
    #if defined DIALOG_TREE_LITE
    {
        dialogid = GetDialogFree();

        if(dialogid == INVALID_DIALOG_ID)
            return 0;


        strcat((dtreeFunction[dialogid][0] = EOS, dtreeFunction[dialogid]), dialog, MAX_DIALOG_NAME);
    }
    #else
    {
        return 0;
    }
    #endif


    if(color[0] != EOS)
        strcat((dtreeDialogColorCaption[dialogid][0] = EOS, dtreeDialogColorCaption[dialogid]), color);


    return strcat((dtreeDefaultDialogCaption[dialogid][0] = EOS, dtreeDefaultDialogCaption[dialogid]), caption, MAX_DIALOG_CAPTION);
}

stock SetDefaultDialogInfo(const dialog[], const info[], const color[]="")
{
    if(info[0] == EOS)
        return 0;


    new dialogid = GetDialogID(dialog);

    if(dialogid == INVALID_DIALOG_ID)
    #if defined DIALOG_TREE_LITE
    {
        dialogid = GetDialogFree();

        if(dialogid == INVALID_DIALOG_ID)
            return 0;


        strcat((dtreeFunction[dialogid][0] = EOS, dtreeFunction[dialogid]), dialog, MAX_DIALOG_NAME);
    }
    #else
    {
        return 0;
    }
    #endif


    if(color[0] != EOS)
        strcat((dtreeDialogColorInfo[dialogid][0] = EOS, dtreeDialogColorInfo[dialogid]), color);


    return strcat((dtreeDefaultDialogInfo[dialogid][0] = EOS, dtreeDefaultDialogInfo[dialogid]), info, MAX_DIALOG_INFO);
}

stock SetDefaultDialogLeft(const dialog[], const left[], const color[]="")
{
    if(left[0] == EOS)
        return 0;


    new dialogid = GetDialogID(dialog);
    
    if(dialogid == INVALID_DIALOG_ID)
    #if defined DIALOG_TREE_LITE
    {
        dialogid = GetDialogFree();

        if(dialogid == INVALID_DIALOG_ID)
            return 0;


        strcat((dtreeFunction[dialogid][0] = EOS, dtreeFunction[dialogid]), dialog, MAX_DIALOG_NAME);
    }
    #else
    {
        return 0;
    }
    #endif


    if(color[0] != EOS)
        strcat((dtreeDialogColorLeft[dialogid][0] = EOS, dtreeDialogColorLeft[dialogid]), color);


    return strcat((dtreeDefaultDialogLeft[dialogid][0] = EOS, dtreeDefaultDialogLeft[dialogid]), left, MAX_DIALOG_BUTTON);
}

stock SetDefaultDialogRight(const dialog[], const right[], const color[]="")
{
    if(right[0] == EOS)
        return 0;


    new dialogid = GetDialogID(dialog);
    
    if(dialogid == INVALID_DIALOG_ID)
    #if defined DIALOG_TREE_LITE
    {
        dialogid = GetDialogFree();

        if(dialogid == INVALID_DIALOG_ID)
            return 0;


        strcat((dtreeFunction[dialogid][0] = EOS, dtreeFunction[dialogid]), dialog, MAX_DIALOG_NAME);
    }
    #else
    {
        return 0;
    }
    #endif


    if(color[0] != EOS)
        strcat((dtreeDialogColorRight[dialogid][0] = EOS, dtreeDialogColorRight[dialogid]), color);


    return strcat((dtreeDefaultDialogRight[dialogid][0] = EOS, dtreeDefaultDialogRight[dialogid]), right, MAX_DIALOG_BUTTON);
}


#if !defined DIALOG_TREE_LITE

    #if defined DIALOG_TREE_WITHOUT_ARRAY

        stock GetDialogReferral(const dialog[], offset)
        {
            new dialogid = GetDialogID(dialog),
                result[SIZE_DIALOG_NAME];

            for(new i = 0, count; i < MAX_DIALOG_ID; i++)
            {
                if(dtreeReferral[i] == INVALID_DIALOG_ID)
                    continue;


                if(dtreeReferral[i] != dialogid)
                    continue;


                if(offset != count)
                {
                    count++;

                    continue;
                }


                strcat((string[0] = EOS, string), dtreeFunction[i], MAX_DIALOG_NAME);

                break;
            }

            return result;
        }

    #else

        stock GetDialogReferral(const dialog[], offset, string[])
        {
            new dialogid = GetDialogID(dialog);

            for(new i = 0, count; i < MAX_DIALOG_ID; i++)
            {
                if(dtreeReferral[i] == INVALID_DIALOG_ID)
                    continue;


                if(dtreeReferral[i] != dialogid)
                    continue;


                if(offset != count)
                {
                    count++;

                    continue;
                }


                strcat((string[0] = EOS, string), dtreeFunction[i], MAX_DIALOG_NAME);

                break;
            }


            return 1;
        }

    #endif

#endif


stock OpenPlayerDialog(playerid, const dialog[]="", style=INVALID_DIALOG_ID, const caption[]="", const info[]="", const left[]="", const right[]="")
{
    new dialogid;
    
    if(dialog[0] == EOS)
    {
        dialogid = dtreePlayerDialogid[playerid];

        if(dialogid == INVALID_DIALOG_ID)
            return 0;
    }
    else
    {
        dialogid = GetDialogID(dialog);

        #if defined DIALOG_TREE_LITE

            if(dialogid == INVALID_DIALOG_ID)
            {
                dialogid = GetDialogFree();

                if(dialogid == INVALID_DIALOG_ID)
                    return 0;


                dtreePlayerDialogid[playerid] = dialogid;

                strcat((dtreeFunction[dialogid][0] = EOS, dtreeFunction[dialogid]), dialog, MAX_DIALOG_NAME);
            }
            else
                dtreePlayerDialogid[playerid] = dialogid;


            if(style == INVALID_DIALOG_ID && dtreeDefaultDialogStyle[dialogid] == INVALID_DIALOG_ID)
                return 0;

            if(caption[0] == EOS && dtreeDefaultDialogCaption[dialogid][0] == EOS)
                return 0;

            if(info[0] == EOS && dtreeDefaultDialogInfo[dialogid][0] == EOS)
                return 0;

            if(left[0] == EOS && dtreeDefaultDialogLeft[dialogid][0] == EOS)
                return 0;

        #else

            dtreePlayerDialogid[playerid] = dialogid;

        #endif
    }


    if(dialogid == INVALID_DIALOG_ID)
        return 0;


    if(style < 0)
    {
        if(dtreeFunctionDialogStyle[dialogid][0] == EOS)
        {
            if(dtreeDefaultDialogStyle[dialogid] == INVALID_DIALOG_ID)
                return 0;


            dtreePlayerDialogStyle[playerid] = dtreeDefaultDialogStyle[dialogid];
        }
        else
            return CallLocalFunction(dtreeFunctionDialogStyle[dialogid], "i", playerid);
    }

    if(dtreePlayerDialogStyle[playerid] < 0)
        dtreePlayerDialogStyle[playerid] = style;


    if(caption[0] == EOS)
    {
        if(dtreeFunctionDialogCaption[dialogid][0] == EOS)
        {
            if(dtreeDefaultDialogCaption[dialogid][0] == EOS)
                return 0;


            UpdateDialogColor(dtreeDefaultDialogCaption[dialogid], dtreeDialogColorCaption[dialogid], dtreePlayerDialogCaption[playerid], MAX_DIALOG_CAPTION);
        }
        else
            return CallLocalFunction(dtreeFunctionDialogCaption[dialogid], "i", playerid);
    }

    if(dtreePlayerDialogCaption[playerid][0] == EOS)
        strcat(dtreePlayerDialogCaption[playerid], caption);


    if(info[0] == EOS)
    {
        if(dtreeFunctionDialogInfo[dialogid][0] == EOS)
        {
            if(dtreeDefaultDialogInfo[dialogid][0] == EOS)
                return 0;


            if(dtreeDefaultDialogStyle[dialogid] == DIALOG_STYLE_MSGBOX ||
               dtreeDefaultDialogStyle[dialogid] == DIALOG_STYLE_INPUT  ||
               dtreeDefaultDialogStyle[dialogid] == DIALOG_STYLE_PASSWORD)
                UpdateDialogColor(dtreeDefaultDialogInfo[dialogid], dtreeDialogColorInfo[dialogid], dtreePlayerDialogInfo[playerid], MAX_DIALOG_INFO);
            else
                strcat((dtreePlayerDialogInfo[playerid][0] = EOS, dtreePlayerDialogInfo[playerid]), dtreeDefaultDialogInfo[dialogid], MAX_DIALOG_INFO);
        }
        else
            return CallLocalFunction(dtreeFunctionDialogInfo[dialogid], "i", playerid);
    }

    if(dtreePlayerDialogInfo[playerid][0] == EOS)
        strcat(dtreePlayerDialogInfo[playerid], info);


    if(left[0] == EOS)
    {
        if(dtreeFunctionDialogLeft[dialogid][0] == EOS)
        {
            if(dtreeDefaultDialogLeft[dialogid][0] == EOS)
                return 0;


            UpdateDialogColor(dtreeDefaultDialogLeft[dialogid], dtreeDialogColorLeft[dialogid], dtreePlayerDialogLeft[playerid], MAX_DIALOG_BUTTON);
        }
        else
            return CallLocalFunction(dtreeFunctionDialogLeft[dialogid], "i", playerid);
    }

    if(dtreePlayerDialogLeft[playerid][0] == EOS)
        strcat(dtreePlayerDialogLeft[playerid], left);


    if(right[0] == EOS)
    {
        if(dtreeFunctionDialogRight[dialogid][0] == EOS)
            UpdateDialogColor(dtreeDefaultDialogRight[dialogid], dtreeDialogColorRight[dialogid], dtreePlayerDialogRight[playerid], MAX_DIALOG_BUTTON);
        else
            return CallLocalFunction(dtreeFunctionDialogRight[dialogid], "i", playerid);
    }

    if(dtreePlayerDialogRight[playerid][0] == EOS)
        strcat(dtreePlayerDialogRight[playerid], right);


    new string[SIZE_DIALOG_INFO];

    #if !defined DIALOG_TREE_WITHOUT_BOOK

        if(CheckDialogStyle(playerid, dialogid, style))
        {
            if(dtreePlayerPage[playerid] == INVALID_DIALOG_ID)
                dtreePlayerPage[playerid] = 0;

            GetDialogPage(playerid, dialogid, dtreePlayerDialogStyle[playerid], dtreePlayerDialogInfo[playerid], string);
        }
        else
            strcat(string, (dtreePlayerDialogInfo[playerid][0] == EOS) ? (info) : (dtreePlayerDialogInfo[playerid]), MAX_DIALOG_INFO);


    #else

        strcat(string, (dtreePlayerDialogInfo[playerid][0] == EOS) ? (info) : (dtreePlayerDialogInfo[playerid]), MAX_DIALOG_INFO);

    #endif


    #if !defined DIALOG_TREE_WITHOUT_BOOK

        if(dtreePlayerDialogStyle[playerid] < DLG_STYLE_BOOK)
            style = dtreePlayerDialogStyle[playerid];

        else if(DLG_STYLE_BOOK <= dtreePlayerDialogStyle[playerid] && dtreePlayerDialogStyle[playerid] < DLG_STYLE_TABBOOK)
            style = DIALOG_STYLE_LIST;

        else if(DLG_STYLE_TABBOOK <= dtreePlayerDialogStyle[playerid] && dtreePlayerDialogStyle[playerid] < DLG_STYLE_TABBOOK_HEADERS)
            style = DIALOG_STYLE_TABLIST;

        else if(DLG_STYLE_TABBOOK_HEADERS <= dtreePlayerDialogStyle[playerid])
            style = DIALOG_STYLE_TABLIST_HEADERS;

    #endif


    if(OnPlayerDialogReceived(playerid, dialog) > 0)
        return ShowPlayerDialog(playerid, DIALOG_ID, style, dtreePlayerDialogCaption[playerid], string, dtreePlayerDialogLeft[playerid], dtreePlayerDialogRight[playerid]);
    else
        return 0;
}


#if !defined DIALOG_TREE_LITE

    stock OpenBackPlayerDialog(playerid, const style=INVALID_DIALOG_ID, const caption[]="", const info[]="", const left[]="", const right[]="")
    {
        new dialogid = dtreePlayerDialogid[playerid];

        if(dialogid == INVALID_DIALOG_ID)
            return 0;


        if(dtreeReferral[dialogid] == INVALID_DIALOG_ID)
            return 0;

        
        dtreePlayerDialogid[playerid] = dtreeReferral[dialogid];
        dialogid = dtreeReferral[dialogid];


        return OpenPlayerDialog(playerid, dtreeFunction[dialogid], style, caption, info, left, right);
    }


    stock OpenNextPlayerDialog(playerid, const dialog[]="", const style=INVALID_DIALOG_ID, const caption[]="", const info[]="", const left[]="", const right[]="")
    {
        new dialogid = dtreePlayerDialogid[playerid];

        if(dialogid == INVALID_DIALOG_ID)
            return 0;


        if(dialog[0] == EOS)
        {
            for(new i = 0; i < MAX_DIALOG_ID; i++)
            {
                if(dtreeReferral[i] != dialogid)
                    continue;

                dialogid = i;

                break;
            }
        }
        else
        {
            dialogid = GetDialogID(dialog);

            if(dialogid == INVALID_DIALOG_ID)
                return 0;
        }


        if(dtreeReferral[dialogid] != dtreePlayerDialogid[playerid])
            return printf("\n[DialogTree] Function tag mismatch (<%s>%s)", dtreeFunction[dtreePlayerDialogid[playerid]], dialog);


        dtreePlayerDialogid[playerid] = dialogid;


        return OpenPlayerDialog(playerid, dtreeFunction[dialogid], style, caption, info, left, right);
    }

#endif


stock DLG_ClosePlayerDialog(playerid)
{
    dtreePlayerDialogid[playerid] = INVALID_DIALOG_ID;

    dtreePlayerDialogStyle[playerid] = INVALID_DIALOG_ID;
    dtreePlayerDialogCaption[playerid][0] = EOS;
    dtreePlayerDialogInfo[playerid][0] = EOS;
    dtreePlayerDialogLeft[playerid][0] = EOS;
    dtreePlayerDialogRight[playerid][0] = EOS;

    #if !defined DIALOG_TREE_WITHOUT_BOOK
        
        dtreePlayerRow[playerid] = 0;
        dtreePlayerPage[playerid] = INVALID_DIALOG_ID;

    #endif


    #if defined DIALOG_BUTTON_ESC
    
        CancelSelectTextDraw(playerid);

    #endif


    #if defined _INC_open_mp

        HidePlayerDialog(playerid);

    #else

        ShowPlayerDialog(playerid, -1, 0, "", "", "", "");

    #endif


    return 1;
}


#if defined DIALOG_TREE_WITHOUT_ARRAY

    stock GetPlayerDialog(playerid)
    {
        new dialogid = dtreePlayerDialogid[playerid],
            result[SIZE_DIALOG_NAME];

        if(dialogid == INVALID_DIALOG_ID)
            return result;


        return dtreeFunction[dialogid];
    }

#else

    stock GetPlayerDialog(playerid, string[])
    {
        new dialogid = dtreePlayerDialogid[playerid];

        if(dialogid == INVALID_DIALOG_ID)
            return 0;


        return strcat((string[0] = EOS, string), dtreeFunction[dialogid], MAX_DIALOG_NAME);
    }

#endif


stock IsPlayerOpenDialog(playerid)
{
    return (dtreePlayerDialogid[playerid] > INVALID_DIALOG_ID);
}


#if !defined DIALOG_TREE_WITHOUT_BOOK

    stock GetPlayerDialogPage(playerid)
    {
        return dtreePlayerPage[playerid];
    }

#endif


stock SetFunctionDialogStyle(const dialog[], const function[])
{
    new dialogid = GetDialogID(dialog);

    if(dialogid == INVALID_DIALOG_ID)
        return 0;


    if(function[0] == EOS)
        return 0;


    return strcat((dtreeFunctionDialogStyle[dialogid][0] = EOS, dtreeFunctionDialogStyle[dialogid]), function, MAX_DIALOG_INFO);
}

stock UpdateDialogStyle(playerid, const style)
{
    new dialogid = dtreePlayerDialogid[playerid];

    if(dialogid == INVALID_DIALOG_ID)
        return 0;


    dtreePlayerDialogStyle[playerid] = style;


    return OpenPlayerDialog(playerid, dtreeFunction[dialogid], dtreePlayerDialogStyle[playerid], dtreePlayerDialogCaption[playerid], dtreePlayerDialogInfo[playerid], dtreePlayerDialogLeft[playerid], dtreePlayerDialogRight[playerid]);
}


stock SetFunctionDialogCaption(const dialog[], const function[])
{
    new dialogid = GetDialogID(dialog);

    if(dialogid == INVALID_DIALOG_ID)
        return 0;


    if(function[0] == EOS)
        return 0;


    return strcat((dtreeFunctionDialogCaption[dialogid][0] = EOS, dtreeFunctionDialogCaption[dialogid]), function, MAX_DIALOG_INFO);
}

stock UpdateDialogCaption(playerid, const caption[])
{
    new dialogid = dtreePlayerDialogid[playerid];

    if(dialogid == INVALID_DIALOG_ID)
        return 0;


    strcat((dtreePlayerDialogCaption[playerid][0] = EOS, dtreePlayerDialogCaption[playerid]), caption, MAX_DIALOG_INFO);


    return OpenPlayerDialog(playerid, dtreeFunction[dialogid], dtreePlayerDialogStyle[playerid], dtreePlayerDialogCaption[playerid], dtreePlayerDialogInfo[playerid], dtreePlayerDialogLeft[playerid], dtreePlayerDialogRight[playerid]);
}


stock SetFunctionDialogInfo(const dialog[], const function[])
{
    new dialogid = GetDialogID(dialog);

    if(dialogid == INVALID_DIALOG_ID)
        return 0;


    if(function[0] == EOS)
        return 0;


    return strcat((dtreeFunctionDialogInfo[dialogid][0] = EOS, dtreeFunctionDialogInfo[dialogid]), function, MAX_DIALOG_INFO);
}

stock UpdateDialogInfo(playerid, const info[])
{
    new dialogid = dtreePlayerDialogid[playerid];

    if(dialogid == INVALID_DIALOG_ID)
        return 0;


    strcat((dtreePlayerDialogInfo[playerid][0] = EOS, dtreePlayerDialogInfo[playerid]), info, MAX_DIALOG_INFO);


    return OpenPlayerDialog(playerid, dtreeFunction[dialogid], dtreePlayerDialogStyle[playerid], dtreePlayerDialogCaption[playerid], dtreePlayerDialogInfo[playerid], dtreePlayerDialogLeft[playerid], dtreePlayerDialogRight[playerid]);
}


stock SetFunctionDialogLeft(const dialog[], const function[])
{
    new dialogid = GetDialogID(dialog);

    if(dialogid == INVALID_DIALOG_ID)
        return 0;


    if(function[0] == EOS)
        return 0;


    return strcat((dtreeFunctionDialogLeft[dialogid][0] = EOS, dtreeFunctionDialogLeft[dialogid]), function, MAX_DIALOG_INFO);
}

stock UpdateDialogLeft(playerid, const left[])
{
    new dialogid = dtreePlayerDialogid[playerid];

    if(dialogid == INVALID_DIALOG_ID)
        return 0;


    strcat((dtreePlayerDialogLeft[playerid][0] = EOS, dtreePlayerDialogLeft[playerid]), left, MAX_DIALOG_INFO);


    return OpenPlayerDialog(playerid, dtreeFunction[dialogid], dtreePlayerDialogStyle[playerid], dtreePlayerDialogCaption[playerid], dtreePlayerDialogInfo[playerid], dtreePlayerDialogLeft[playerid], dtreePlayerDialogRight[playerid]);
}


stock SetFunctionDialogRight(const dialog[], const function[])
{
    new dialogid = GetDialogID(dialog);

    if(dialogid == INVALID_DIALOG_ID)
        return 0;


    if(function[0] == EOS)
        return 0;


    return strcat((dtreeFunctionDialogRight[dialogid][0] = EOS, dtreeFunctionDialogRight[dialogid]), function, MAX_DIALOG_INFO);
}

stock UpdateDialogRight(playerid, const right[])
{
    new dialogid = dtreePlayerDialogid[playerid];

    if(dialogid == INVALID_DIALOG_ID)
        return 0;


    strcat((dtreePlayerDialogRight[playerid][0] = EOS, dtreePlayerDialogRight[playerid]), right, MAX_DIALOG_INFO);


    return OpenPlayerDialog(playerid, dtreeFunction[dialogid], dtreePlayerDialogStyle[playerid], dtreePlayerDialogCaption[playerid], dtreePlayerDialogInfo[playerid], dtreePlayerDialogLeft[playerid], dtreePlayerDialogRight[playerid]);
}


public OnPlayerDialogReceived(playerid, const dialog[])
{
    #if defined DLG_OnPlayerDialogReceived
        return DLG_OnPlayerDialogReceived(playerid, dialog);
    #else
        return 1;
    #endif
}

#if defined _ALS_OnPlayerDialogReceived
    #undef OnPlayerDialogReceived
#else
    #define _ALS_OnPlayerDialogReceived
#endif
#define OnPlayerDialogReceived DLG_OnPlayerDialogReceived
#if defined DLG_OnPlayerDialogReceived
    forward DLG_OnPlayerDialogReceived(playerid, const dialog[]);
#endif


/* ---------------------------------------------[DIALOG TREE EDITOR]--------------------------------------------- */


#if defined DIALOG_TREE_EDITOR

    static const exportDialogTree[] = "DialogTree_%s.txt";

    static bool:dteditMode,
           bool:dteditView,

           dteditFunction[SIZE_DIALOG_NAME],
           dteditReferral[SIZE_DIALOG_NAME],

           dteditStyle,
           dteditStyleFunction[SIZE_DIALOG_NAME],

           dteditCaption[SIZE_DIALOG_CAPTION],
           dteditCaptionFunction[SIZE_DIALOG_NAME],
           dteditCaptionColor[SIZE_DIALOG_COLOR],

           dteditInfo[SIZE_DIALOG_CAPTION],
           dteditInfoFunction[SIZE_DIALOG_NAME],
           dteditInfoColor[SIZE_DIALOG_COLOR],

           dteditLeft[SIZE_DIALOG_CAPTION],
           dteditLeftFunction[SIZE_DIALOG_NAME],
           dteditLeftColor[SIZE_DIALOG_COLOR],

           dteditRight[SIZE_DIALOG_CAPTION],
           dteditRightFunction[SIZE_DIALOG_NAME],
           dteditRightColor[SIZE_DIALOG_COLOR],

           dteditButtonLeft,
           dteditStringLeft[SIZE_DIALOG_NAME],

           dteditButtonRight,
           dteditStringRight[SIZE_DIALOG_NAME];


    public OnGameModeInit()
    {
        if(CreateDialog(Dialog:DTE@Create))
        {
            SetDefaultDialogStyle(Dialog:DTE@Create, DIALOG_STYLE_INPUT);
            SetDefaultDialogCaption(Dialog:DTE@Create, "Dialog Tree Editor", "ffffff");
            SetDefaultDialogInfo(Dialog:DTE@Create, "Укажите имя новго диалога:", "ffffff");
            SetDefaultDialogLeft(Dialog:DTE@Create, "Принять");
            SetDefaultDialogRight(Dialog:DTE@Create, "Закрыть");
        }

        if(CreateDialog(Dialog:DTE@Setting))
        {
            SetDefaultDialogStyle(Dialog:DTE@Setting, DIALOG_STYLE_LIST);
            SetFunctionDialogCaption(Dialog:DTE@Setting, "DTE_Name");
            SetFunctionDialogInfo(Dialog:DTE@Setting, "DTE_Setting");
            SetDefaultDialogLeft(Dialog:DTE@Setting, "Выбрать");
            SetDefaultDialogRight(Dialog:DTE@Setting, "Закрыть");
        }

        if(CreateDialog(Dialog:DTE@Exit))
        {
            SetDefaultDialogStyle(Dialog:DTE@Exit, DIALOG_STYLE_MSGBOX);
            SetFunctionDialogCaption(Dialog:DTE@Exit, "DTE_Name");
            SetDefaultDialogInfo(Dialog:DTE@Exit, "Вы действительно хотите отменить создание диалога?", "ffffff");
            SetDefaultDialogLeft(Dialog:DTE@Exit, "Закрыть", "ff0000");
            SetDefaultDialogRight(Dialog:DTE@Exit, "Назад");
        }

        if(CreateDialog(Dialog:DTE@Setting, Dialog:DTE@Link))
        {
            SetFunctionDialogStyle(Dialog:DTE@Link, "DTE_StyleLink");
            SetFunctionDialogCaption(Dialog:DTE@Link, "DTE_Name");
            SetFunctionDialogInfo(Dialog:DTE@Link, "DTE_InfoLink");
            SetDefaultDialogLeft(Dialog:DTE@Link, "Выбрать");
            SetDefaultDialogRight(Dialog:DTE@Link, "Назад");
        }

        if(CreateDialog(Dialog:DTE@Link, Dialog:DTE@LinkNew))
        {
            SetDefaultDialogStyle(Dialog:DTE@LinkNew, DIALOG_STYLE_INPUT);
            SetFunctionDialogCaption(Dialog:DTE@LinkNew, "DTE_Name");
            SetDefaultDialogInfo(Dialog:DTE@LinkNew, "Укажите родительский элемент:", "ffffff");
            SetDefaultDialogLeft(Dialog:DTE@LinkNew, "Принять");
            SetDefaultDialogRight(Dialog:DTE@LinkNew, "Назад");
        }

        if(CreateDialog(Dialog:DTE@Link, Dialog:DTE@LinkDelete))
        {
            SetDefaultDialogStyle(Dialog:DTE@LinkDelete, DIALOG_STYLE_MSGBOX);
            SetFunctionDialogCaption(Dialog:DTE@LinkDelete, "DTE_Name");
            SetDefaultDialogInfo(Dialog:DTE@LinkDelete, "Вы действительно хотите удалить родительский элемент?", "ffffff");
            SetDefaultDialogLeft(Dialog:DTE@LinkDelete, "Принять");
            SetDefaultDialogRight(Dialog:DTE@LinkDelete, "Назад");
        }

        if(CreateDialog(Dialog:DTE@Setting, Dialog:DTE@Style))
        {
            SetFunctionDialogStyle(Dialog:DTE@Style, "DTE_StyleStyle");
            SetFunctionDialogCaption(Dialog:DTE@Style, "DTE_Name");
            SetFunctionDialogInfo(Dialog:DTE@Style, "DTE_InfoStyle");
            SetDefaultDialogLeft(Dialog:DTE@Style, "Выбрать");
            SetDefaultDialogRight(Dialog:DTE@Style, "Назад");
        }

        if(CreateDialog(Dialog:DTE@Style, Dialog:DTE@StyleDefault))
        {
            SetDefaultDialogStyle(Dialog:DTE@StyleDefault, DIALOG_STYLE_LIST);
            SetFunctionDialogCaption(Dialog:DTE@StyleDefault, "DTE_Name");
            SetDefaultDialogInfo(Dialog:DTE@StyleDefault, "DIALOG_STYLE_MSGBOX\nDIALOG_STYLE_INPUT\nDIALOG_STYLE_LIST\nDIALOG_STYLE_PASSWORD\nDIALOG_STYLE_TABLIST\nDIALOG_STYLE_TABLIST_HEADERS\nDIALOG_STYLE_BOOK<>\nDIALOG_STYLE_TABBOOK<>\nDIALOG_STYLE_TABBOOK_HEADERS<>", "ffffff");
            SetDefaultDialogLeft(Dialog:DTE@StyleDefault, "Выбрать");
            SetDefaultDialogRight(Dialog:DTE@StyleDefault, "Назад");
        }

        if(CreateDialog(Dialog:DTE@Style, Dialog:DTE@StyleFunction))
        {
            SetDefaultDialogStyle(Dialog:DTE@StyleFunction, DIALOG_STYLE_INPUT);
            SetFunctionDialogCaption(Dialog:DTE@StyleFunction, "DTE_Name");
            SetDefaultDialogInfo(Dialog:DTE@StyleFunction, "Укажите имя функции:", "ffffff");
            SetDefaultDialogLeft(Dialog:DTE@StyleFunction, "Принять");
            SetDefaultDialogRight(Dialog:DTE@StyleFunction, "Назад");
        }

        if(CreateDialog(Dialog:DTE@Style, Dialog:DTE@StylePage))
        {
            SetDefaultDialogStyle(Dialog:DTE@StylePage, DIALOG_STYLE_INPUT);
            SetFunctionDialogCaption(Dialog:DTE@StylePage, "DTE_Name");
            SetDefaultDialogInfo(Dialog:DTE@StylePage, "Укажите количество строк на одной странице:", "ffffff");
            SetDefaultDialogLeft(Dialog:DTE@StylePage, "Принять");
            SetDefaultDialogRight(Dialog:DTE@StylePage, "Отмена");
        }

        if(CreateDialog(Dialog:DTE@Setting, Dialog:DTE@Caption))
        {
            SetFunctionDialogStyle(Dialog:DTE@Caption, "DTE_StyleCaption");
            SetFunctionDialogCaption(Dialog:DTE@Caption, "DTE_Name");
            SetFunctionDialogInfo(Dialog:DTE@Caption, "DTE_InfoCaption");
            SetDefaultDialogLeft(Dialog:DTE@Caption, "Выбрать");
            SetDefaultDialogRight(Dialog:DTE@Caption, "Назад");
        }

        if(CreateDialog(Dialog:DTE@Caption, Dialog:DTE@CaptionDefault))
        {
            SetDefaultDialogStyle(Dialog:DTE@CaptionDefault, DIALOG_STYLE_INPUT);
            SetFunctionDialogCaption(Dialog:DTE@CaptionDefault, "DTE_Name");
            SetDefaultDialogInfo(Dialog:DTE@CaptionDefault, "Укажите название:", "ffffff");
            SetDefaultDialogLeft(Dialog:DTE@CaptionDefault, "Принять");
            SetDefaultDialogRight(Dialog:DTE@CaptionDefault, "Назад");
        }


        if(CreateDialog(Dialog:DTE@Caption, Dialog:DTE@CaptionFunction))
        {
            SetDefaultDialogStyle(Dialog:DTE@CaptionFunction, DIALOG_STYLE_INPUT);
            SetFunctionDialogCaption(Dialog:DTE@CaptionFunction, "DTE_Name");
            SetDefaultDialogInfo(Dialog:DTE@CaptionFunction, "Укажите имя функции:", "ffffff");
            SetDefaultDialogLeft(Dialog:DTE@CaptionFunction, "Принять");
            SetDefaultDialogRight(Dialog:DTE@CaptionFunction, "Назад");
        }


        if(CreateDialog(Dialog:DTE@Caption, Dialog:DTE@CaptionColor))
        {
            SetDefaultDialogStyle(Dialog:DTE@CaptionColor, DIALOG_STYLE_INPUT);
            SetFunctionDialogCaption(Dialog:DTE@CaptionColor, "DTE_Name");
            SetDefaultDialogInfo(Dialog:DTE@CaptionColor, "Укажите цвет строки в формате {FF0000}RR{00FF00}GG{0000FF}BB{ffffff}:", "ffffff");
            SetDefaultDialogLeft(Dialog:DTE@CaptionColor, "Принять");
            SetDefaultDialogRight(Dialog:DTE@CaptionColor, "Назад");
        }


        if(CreateDialog(Dialog:DTE@Setting, Dialog:DTE@Info))
        {
            SetFunctionDialogStyle(Dialog:DTE@Info, "DTE_StyleInfo");
            SetFunctionDialogCaption(Dialog:DTE@Info, "DTE_Name");
            SetFunctionDialogInfo(Dialog:DTE@Info, "DTE_InfoInfo");
            SetDefaultDialogLeft(Dialog:DTE@Info, "Выбрать");
            SetDefaultDialogRight(Dialog:DTE@Info, "Назад");
        }


        if(CreateDialog(Dialog:DTE@Info, Dialog:DTE@InfoDefault))
        {
            SetDefaultDialogStyle(Dialog:DTE@InfoDefault, DIALOG_STYLE_INPUT);
            SetFunctionDialogCaption(Dialog:DTE@InfoDefault, "DTE_Name");
            SetDefaultDialogInfo(Dialog:DTE@InfoDefault, "Укажите информацию:", "ffffff");
            SetDefaultDialogLeft(Dialog:DTE@InfoDefault, "Принять");
            SetDefaultDialogRight(Dialog:DTE@InfoDefault, "Назад");
        }


        if(CreateDialog(Dialog:DTE@Info, Dialog:DTE@InfoFunction))
        {
            SetDefaultDialogStyle(Dialog:DTE@InfoFunction, DIALOG_STYLE_INPUT);
            SetFunctionDialogCaption(Dialog:DTE@InfoFunction, "DTE_Name");
            SetDefaultDialogInfo(Dialog:DTE@InfoFunction, "Укажите имя функции:", "ffffff");
            SetDefaultDialogLeft(Dialog:DTE@InfoFunction, "Принять");
            SetDefaultDialogRight(Dialog:DTE@InfoFunction, "Назад");
        }


        if(CreateDialog(Dialog:DTE@Info, Dialog:DTE@InfoColor))
        {
            SetDefaultDialogStyle(Dialog:DTE@InfoColor, DIALOG_STYLE_INPUT);
            SetFunctionDialogCaption(Dialog:DTE@InfoColor, "DTE_Name");
            SetDefaultDialogInfo(Dialog:DTE@InfoColor, "Укажите цвет строки в формате {FF0000}RR{00FF00}GG{0000FF}BB{ffffff}:", "ffffff");
            SetDefaultDialogLeft(Dialog:DTE@InfoColor, "Принять");
            SetDefaultDialogRight(Dialog:DTE@InfoColor, "Назад");
        }

        
        if(CreateDialog(Dialog:DTE@Setting, Dialog:DTE@Left))
        {
            SetFunctionDialogStyle(Dialog:DTE@Left, "DTE_StyleLeft");
            SetFunctionDialogCaption(Dialog:DTE@Left, "DTE_Name");
            SetFunctionDialogInfo(Dialog:DTE@Left, "DTE_InfoLeft");
            SetDefaultDialogLeft(Dialog:DTE@Left, "Выбрать");
            SetDefaultDialogRight(Dialog:DTE@Left, "Назад");
        }


        if(CreateDialog(Dialog:DTE@Left, Dialog:DTE@LeftDefault))
        {
            SetDefaultDialogStyle(Dialog:DTE@LeftDefault, DIALOG_STYLE_INPUT);
            SetFunctionDialogCaption(Dialog:DTE@LeftDefault, "DTE_Name");
            SetDefaultDialogInfo(Dialog:DTE@LeftDefault, "Укажите левую кнопку:", "ffffff");
            SetDefaultDialogLeft(Dialog:DTE@LeftDefault, "Принять");
            SetDefaultDialogRight(Dialog:DTE@LeftDefault, "Назад");
        }


        if(CreateDialog(Dialog:DTE@Left, Dialog:DTE@LeftFunction))
        {
            SetDefaultDialogStyle(Dialog:DTE@LeftFunction, DIALOG_STYLE_INPUT);
            SetFunctionDialogCaption(Dialog:DTE@LeftFunction, "DTE_Name");
            SetDefaultDialogInfo(Dialog:DTE@LeftFunction, "Укажите имя функции:", "ffffff");
            SetDefaultDialogLeft(Dialog:DTE@LeftFunction, "Принять");
            SetDefaultDialogRight(Dialog:DTE@LeftFunction, "Назад");
        }


        if(CreateDialog(Dialog:DTE@Left, Dialog:DTE@LeftColor))
        {
            SetDefaultDialogStyle(Dialog:DTE@LeftColor, DIALOG_STYLE_INPUT);
            SetFunctionDialogCaption(Dialog:DTE@LeftColor, "DTE_Name");
            SetDefaultDialogInfo(Dialog:DTE@LeftColor, "Укажите цвет строки в формате {FF0000}RR{00FF00}GG{0000FF}BB{ffffff}:", "ffffff");
            SetDefaultDialogLeft(Dialog:DTE@LeftColor, "Принять");
            SetDefaultDialogRight(Dialog:DTE@LeftColor, "Назад");
        }


        if(CreateDialog(Dialog:DTE@Setting, Dialog:DTE@Right))
        {
            SetFunctionDialogStyle(Dialog:DTE@Right, "DTE_StyleRight");
            SetFunctionDialogCaption(Dialog:DTE@Right, "DTE_Name");
            SetFunctionDialogInfo(Dialog:DTE@Right, "DTE_InfoRight");
            SetDefaultDialogLeft(Dialog:DTE@Right, "Выбрать");
            SetDefaultDialogRight(Dialog:DTE@Right, "Назад");
        }


        if(CreateDialog(Dialog:DTE@Right, Dialog:DTE@RightDefault))
        {
            SetDefaultDialogStyle(Dialog:DTE@RightDefault, DIALOG_STYLE_INPUT);
            SetFunctionDialogCaption(Dialog:DTE@RightDefault, "DTE_Name");
            SetDefaultDialogInfo(Dialog:DTE@RightDefault, "Укажите правую кнопку:", "ffffff");
            SetDefaultDialogLeft(Dialog:DTE@RightDefault, "Принять");
            SetDefaultDialogRight(Dialog:DTE@RightDefault, "Назад");
        }


        if(CreateDialog(Dialog:DTE@Right, Dialog:DTE@RightFunction))
        {
            SetDefaultDialogStyle(Dialog:DTE@RightFunction, DIALOG_STYLE_INPUT);
            SetFunctionDialogCaption(Dialog:DTE@RightFunction, "DTE_Name");
            SetDefaultDialogInfo(Dialog:DTE@RightFunction, "Укажите имя функции:", "ffffff");
            SetDefaultDialogLeft(Dialog:DTE@RightFunction, "Принять");
            SetDefaultDialogRight(Dialog:DTE@RightFunction, "Назад");
        }


        if(CreateDialog(Dialog:DTE@Right, Dialog:DTE@RightColor))
        {
            SetDefaultDialogStyle(Dialog:DTE@RightColor, DIALOG_STYLE_INPUT);
            SetFunctionDialogCaption(Dialog:DTE@RightColor, "DTE_Name");
            SetDefaultDialogInfo(Dialog:DTE@RightColor, "Укажите цвет строки в формате {ff0000}RR{00ff00}GG{0000ff}BB{ffffff}:", "ffffff");
            SetDefaultDialogLeft(Dialog:DTE@RightColor, "Принять");
            SetDefaultDialogRight(Dialog:DTE@RightColor, "Назад");
        }


        if(CreateDialog(Dialog:DTE@Setting, Dialog:DTE@Button))
        {
            SetDefaultDialogStyle(Dialog:DTE@Button, DIALOG_STYLE_TABLIST);
            SetFunctionDialogCaption(Dialog:DTE@Button, "DTE_Name");
            SetFunctionDialogInfo(Dialog:DTE@Button, "DTE_Button");
            SetDefaultDialogLeft(Dialog:DTE@Button, "Выбрать");
            SetDefaultDialogRight(Dialog:DTE@Button, "Назад");
        }


        if(CreateDialog(Dialog:DTE@Button, Dialog:DTE@ButtonLeft))
        {
            SetDefaultDialogStyle(Dialog:DTE@ButtonLeft, DIALOG_STYLE_LIST);
            SetFunctionDialogCaption(Dialog:DTE@ButtonLeft, "DTE_Name");
            SetDefaultDialogInfo(Dialog:DTE@ButtonLeft, "Перейти на следующий\nПерейти на предыдущий\nЗакрыть", "ffffff");
            SetDefaultDialogLeft(Dialog:DTE@ButtonLeft, "Выбрать");
            SetDefaultDialogRight(Dialog:DTE@ButtonLeft, "Назад");
        }


        if(CreateDialog(Dialog:DTE@Button, Dialog:DTE@ButtonRight))
        {
            SetDefaultDialogStyle(Dialog:DTE@ButtonRight, DIALOG_STYLE_LIST);
            SetFunctionDialogCaption(Dialog:DTE@ButtonRight, "DTE_Name");
            SetDefaultDialogInfo(Dialog:DTE@ButtonRight, "Перейти на предыдущий\nПерейти на следующий\nЗакрыть\nДругое", "ffffff");
            SetDefaultDialogLeft(Dialog:DTE@ButtonRight, "Выбрать");
            SetDefaultDialogRight(Dialog:DTE@ButtonRight, "Назад");
        }


        if(CreateDialog(Dialog:DTE@ButtonLeft, Dialog:DTE@ButtonLeftInput))
        {
            SetDefaultDialogStyle(Dialog:DTE@ButtonLeftInput, DIALOG_STYLE_INPUT);
            SetFunctionDialogCaption(Dialog:DTE@ButtonLeftInput, "DTE_Name");
            SetDefaultDialogInfo(Dialog:DTE@ButtonLeftInput, "Укажите имя диалога при переходе:\n{888888}   - оставьте поле пустым, чтобы перейти к первому привязанному\n{888888}   - укажите * для перехода в зависимости от listitem", "ffffff");
            SetDefaultDialogLeft(Dialog:DTE@ButtonLeftInput, "Принять");
            SetDefaultDialogRight(Dialog:DTE@ButtonLeftInput, "Назад");
        }


        if(CreateDialog(Dialog:DTE@ButtonRight, Dialog:DTE@ButtonRightInput))
        {
            SetDefaultDialogStyle(Dialog:DTE@ButtonRightInput, DIALOG_STYLE_INPUT);
            SetFunctionDialogCaption(Dialog:DTE@ButtonRightInput, "DTE_Name");
            SetDefaultDialogInfo(Dialog:DTE@ButtonRightInput, "Укажите имя диалога при переходе:\n{888888}   - оставьте поле пустым, чтобы перейти к первому привязанному\n{888888}   - укажите * для перехода в зависимости от listitem", "ffffff");
            SetDefaultDialogLeft(Dialog:DTE@ButtonRightInput, "Принять");
            SetDefaultDialogRight(Dialog:DTE@ButtonRightInput, "Назад");
        }


        #if defined DLGDTR_OnGameModeInit
            return DLGDTR_OnGameModeInit();
        #else
            return 1;
        #endif
    }

    #if defined _ALS_OnGameModeInit
        #undef OnGameModeInit
    #else
        #define _ALS_OnGameModeInit
    #endif
    #define OnGameModeInit DLGDTR_OnGameModeInit
    #if defined DLGDTR_OnGameModeInit
        forward DLGDTR_OnGameModeInit();
    #endif


    stock DialogTreeEditor(playerid)
    {
        if(dteditMode && !dteditView)
            return 0;


        dteditMode = true;


        if(dteditView)
        {
            dteditView = false;

            return OpenPlayerDialog(playerid, Dialog:DTE@Setting);
        }
        else
            return OpenPlayerDialog(playerid, Dialog:DTE@Create);
    }

    static stock DTE@Clear()
    {
        dteditFunction[0] = EOS;
        dteditReferral[0] = EOS;

        dteditStyle = INVALID_DIALOG_ID;
        dteditStyleFunction[0] = EOS;

        dteditCaption[0] = EOS;
        dteditCaptionFunction[0] = EOS;
        dteditCaptionColor[0] = EOS;

        dteditInfo[0] = EOS;
        dteditInfoFunction[0] = EOS;
        dteditInfoColor[0] = EOS;

        dteditLeft[0] = EOS;
        dteditLeftFunction[0] = EOS;
        dteditLeftColor[0] = EOS;

        dteditRight[0] = EOS;
        dteditRightFunction[0] = EOS;
        dteditRightColor[0] = EOS;

        dteditButtonLeft = INVALID_DIALOG_ID;
        dteditStringLeft[0] = EOS;

        dteditButtonRight = INVALID_DIALOG_ID;
        dteditStringRight[0] = EOS;


        return 1;
    }

    static stock DTE@IsHex(const string[])
    {
        new bool:result = true;

        for(new i = 0; i < 6; i++)
        {
            switch(string[i])
            {
                case 'a'..'f', 'A'..'F', '0'..'9':
                    continue;

                default:
                    result = false;
            }
        }


        return result;
    }

    stock DTE@ExportCreate(playerid)
    {
        static const createStart[] =
                                "public OnGameModeInit()\n\
                                {\n    \
                                    if(CreateDialog(%s))\n    \
                                    {%s%s%s%s%s%s%s%s%s%s%s";

        static const createEnd[] =
                                "\n    }\n\n    \
                                return 1;\n\
                                }";


        new function[((MAX_DIALOG_NAME+7)*2+2+1)];

        if(dteditReferral[0] == EOS)
        {
            strcat(function, "Dialog:");
            strcat(function, dteditFunction);
        }
        else
            format(function, sizeof function, "Dialog:%s, Dialog:%s", dteditReferral, dteditFunction);


        static const stringStyleDefault[] = "\n        SetDefaultDialogStyle(Dialog:%s, %s);";
        new styleDefault[(sizeof stringStyleDefault+MAX_DIALOG_NAME+34)];

        if(dteditStyle != INVALID_DIALOG_ID)
        {
            new text[(30+4+1)];

            if(dteditStyle == DIALOG_STYLE_MSGBOX)
                strcat(text, "DIALOG_STYLE_MSGBOX");

            else if(dteditStyle == DIALOG_STYLE_INPUT)
                strcat(text, "DIALOG_STYLE_INPUT");

            else if(dteditStyle == DIALOG_STYLE_LIST)
                strcat(text, "DIALOG_STYLE_LIST");

            else if(dteditStyle == DIALOG_STYLE_PASSWORD)
                strcat(text, "DIALOG_STYLE_PASSWORD");

            else if(dteditStyle == DIALOG_STYLE_TABLIST)
                strcat(text, "DIALOG_STYLE_TABLIST");

            else if(dteditStyle == DIALOG_STYLE_TABLIST_HEADERS)
                strcat(text, "DIALOG_STYLE_TABLIST_HEADERS");

            else if(DLG_STYLE_BOOK <= dteditStyle && dteditStyle < DLG_STYLE_TABBOOK)
                format(text, sizeof text, "DIALOG_STYLE_BOOK<%i>", (dteditStyle/DLG_STYLE_BOOK));

            else if(DLG_STYLE_TABBOOK <= dteditStyle && dteditStyle < DLG_STYLE_TABBOOK_HEADERS)
                format(text, sizeof text, "DIALOG_STYLE_TABBOOK<%i>", (dteditStyle/DLG_STYLE_TABBOOK));

            else if(DLG_STYLE_TABBOOK_HEADERS <= dteditStyle)
                format(text, sizeof text, "DIALOG_STYLE_TABBOOK_HEADERS<%i>", (dteditStyle/DLG_STYLE_TABBOOK_HEADERS));


            format(styleDefault, sizeof styleDefault, stringStyleDefault, dteditFunction, text);
        }

        static const stringStyleFunction[] = "\n        SetFunctionDialogStyle(Dialog:%s, \"%s\");";
        new styleFunction[(sizeof stringStyleFunction+MAX_DIALOG_NAME+MAX_DIALOG_NAME)];

        if(dteditStyleFunction[0] != EOS)
            format(styleFunction, sizeof styleFunction, stringStyleFunction, dteditFunction, dteditStyleFunction);


        static const stringCaptionDefault[] = "\n        SetDefaultDialogCaption(Dialog:%s, \"%s\"";
        new captionDefault[(sizeof stringCaptionDefault+MAX_DIALOG_NAME+MAX_DIALOG_CAPTION+12)];

        if(dteditCaption[0] != EOS)
            format(captionDefault, sizeof captionDefault, stringCaptionDefault, dteditFunction, dteditCaption);

        if(captionDefault[0] != EOS)
        {
            if(dteditCaptionColor[0] != EOS)
            {
                strcat(captionDefault, ", \"");
                strcat(captionDefault, dteditCaptionColor);
                strcat(captionDefault, "\"");
            }

            strcat(captionDefault, ");");
        }

        static const stringCaptionFunction[] = "\n        SetFunctionDialogCaption(Dialog:%s, \"%s\");";
        new captionFunction[(sizeof stringCaptionFunction+MAX_DIALOG_NAME+MAX_DIALOG_NAME)];

        if(dteditCaptionFunction[0] != EOS)
            format(captionFunction, sizeof captionFunction, stringCaptionFunction, dteditFunction, dteditCaptionFunction);


        static const stringInfoDefault[] = "\n        SetDefaultDialogInfo(Dialog:%s, \"%s\"";
        new infoDefault[(sizeof stringInfoDefault+MAX_DIALOG_NAME+MAX_DIALOG_INFO+12)];

        if(dteditInfo[0] != EOS)
            format(infoDefault, sizeof infoDefault, stringInfoDefault, dteditFunction, dteditInfo);

        if(infoDefault[0] != EOS)
        {
            if(dteditInfoColor[0] != EOS)
            {
                strcat(infoDefault, ", \"");
                strcat(infoDefault, dteditInfoColor);
                strcat(infoDefault, "\"");
            }

            strcat(infoDefault, ");");
        }

        static const stringInfoFunction[] = "\n        SetFunctionDialogInfo(Dialog:%s, \"%s\");";
        new infoFunction[(sizeof stringInfoFunction+MAX_DIALOG_NAME+MAX_DIALOG_NAME)];

        if(dteditInfoFunction[0] != EOS)
            format(infoFunction, sizeof infoFunction, stringInfoFunction, dteditFunction, dteditInfoFunction);


        static const stringLeftDefault[] = "\n        SetDefaultDialogLeft(Dialog:%s, \"%s\"";
        new leftDefault[(sizeof stringLeftDefault+MAX_DIALOG_NAME+MAX_DIALOG_BUTTON+12)];

        if(dteditLeft[0] != EOS)
            format(leftDefault, sizeof leftDefault, stringLeftDefault, dteditFunction, dteditLeft);

        if(dteditLeft[0] != EOS)
        {
            if(dteditLeftColor[0] != EOS)
            {
                strcat(leftDefault, ", \"");
                strcat(leftDefault, dteditLeftColor);
                strcat(leftDefault, "\"");
            }

            strcat(leftDefault, ");");
        }

        static const stringLeftFunction[] = "\n        SetFunctionDialogLeft(Dialog:%s, \"%s\");";
        new leftFunction[(sizeof stringLeftFunction+MAX_DIALOG_NAME+MAX_DIALOG_NAME)];

        if(dteditLeftFunction[0] != EOS)
            format(leftFunction, sizeof leftFunction, stringLeftFunction, dteditFunction, dteditLeftFunction);


        static const stringRightDefault[] = "\n        SetDefaultDialogRight(Dialog:%s, \"%s\"";
        new rightDefault[(sizeof stringRightDefault+MAX_DIALOG_NAME+MAX_DIALOG_BUTTON+12)];

        if(dteditRight[0] != EOS)
            format(rightDefault, sizeof rightDefault, stringRightDefault, dteditFunction, dteditRight);

        if(dteditRight[0] != EOS)
        {
            if(dteditRightColor[0] != EOS)
            {
                strcat(rightDefault, ", \"");
                strcat(rightDefault, dteditRightColor);
                strcat(rightDefault, "\"");
            }

            strcat(rightDefault, ");");
        }

        static const stringRightFunction[] = "\n        SetFunctionDialogRight(Dialog:%s, \"%s\");";
        new rightFunction[(sizeof stringRightFunction+MAX_DIALOG_NAME+MAX_DIALOG_NAME)];

        if(dteditRightFunction[0] != EOS)
            format(rightFunction, sizeof rightFunction, stringRightFunction, dteditFunction, dteditRightFunction);


        static string[1300];

        format(string, sizeof string, createStart, function, styleDefault, styleFunction, captionDefault, captionFunction, infoDefault, infoFunction, leftDefault, leftFunction, rightDefault, rightFunction, createEnd);


        new name[(sizeof exportDialogTree+MAX_DIALOG_NAME)];

        format(name, sizeof name, exportDialogTree, dteditFunction);


        new File:file = fopen(name, io_readwrite);

        fwrite(file, string);

        fclose(file);


        return DTE@ExportOnDialog(playerid);
    }

    static stock DTE@ExportOnDialog(playerid)
    {
        static const stringStart[] =
                                "\n\nOnDialog:%s(playerid)\n\
                                {";

        static const stringEnd[] =
                                "\n}\n\n";


        static const stringRight1[] =
                                    "\n    if(IsDialogResponseRight())\n        \
                                    return OpenBackPlayerDialog(playerid);\n";

        static const stringRight2[] =
                                    "\n    if(IsDialogResponseRight())\n        \
                                    return ClosePlayerDialog(playerid);\n";

        static const stringRight3[] =
                                    "\n    if(IsDialogResponseRight())\n    \
                                    {\n        \
                                    //\n\n        \
                                    return ClosePlayerDialog(playerid);\n    \
                                    }\n";

        static const stringRight4[] =
                                    "\n    if(IsDialogResponseRight())\n        \
                                        return OpenNextPlayerDialog(playerid);\n";

        static const stringRight5[] =
                                    "\n    if(IsDialogResponseRight())\n        \
                                        return OpenNextPlayerDialog(playerid, Dialog:%s);\n";

        #if defined DIALOG_TREE_WITHOUT_ARRAY

            static const stringRight6[] =
                                        "\n    if(IsDialogResponseRight())\n        \
                                        return OpenNextPlayerDialog(playerid, GetDialogReferral(Dialog:%s, GetDialogListitem()));\n";

        #else
        
            static const stringRight6[] =
                                        "\n    if(IsDialogResponseRight())\n    \
                                        {\n        \
                                        new dialog[SIZE_DIALOG_NAME];\n\n        \
                                        GetDialogReferral(Dialog:%s, GetDialogListitem(), dialog);\n\n        \
                                        return OpenNextPlayerDialog(playerid, dialog);\n    \
                                        }\n";

        #endif


        static const stringLeft1[] =
                                    "\n    return OpenBackPlayerDialog(playerid);";

        static const stringLeft2[] =
                                    "\n    return ClosePlayerDialog(playerid);";

        static const stringLeft3[] =
                                    "\n    return OpenNextPlayerDialog(playerid);";

        static const stringLeft4[] =
                                    "\n    return OpenNextPlayerDialog(playerid, Dialog:%s);";

        #if defined DIALOG_TREE_WITHOUT_ARRAY

            static const stringLeft5[] =
                                        "\n    return OpenNextPlayerDialog(playerid, GetDialogReferral(Dialog:%s, GetDialogListitem()));";

        #else
        
            static const stringLeft5[] =
                                        "\n    new dialog[SIZE_DIALOG_NAME];\n\n    \
                                        GetDialogReferral(Dialog:%s, GetDialogListitem(), dialog);\n\n    \
                                        return OpenNextPlayerDialog(playerid, dialog);";

        #endif


        static string[550];

        format(string, sizeof string, stringStart, dteditFunction);


        if(dteditButtonRight != INVALID_DIALOG_ID)
        {
            if(dteditStringRight[0] == '*' && dteditStringRight[1] == EOS)
            {
                new text[(sizeof stringRight6+MAX_DIALOG_NAME)];

                format(text, sizeof text, stringRight6, dteditFunction);
                strcat(string, text);
            }
            else
            {
                switch(dteditButtonRight)
                {
                    case 1:
                        strcat(string, stringRight1);

                    case 2:
                        strcat(string, stringRight2);

                    case 3:
                        strcat(string, stringRight3);

                    default:
                    {
                        if(dteditStringRight[0] == EOS)
                            strcat(string, stringRight4);
                        else
                        {
                            new text[(sizeof stringRight5+MAX_DIALOG_NAME)];

                            format(text, sizeof text, stringRight5, dteditStringRight);
                            strcat(string, text);
                        }
                    }
                }
            }
        }


        strcat(string, "\n    //");


        if(dteditButtonLeft != INVALID_DIALOG_ID)
        {
            strcat(string, "\n");

            if(dteditStringLeft[0] == '*' && dteditStringLeft[1] == EOS)
            {
                new text[(sizeof stringLeft5+MAX_DIALOG_NAME)];

                format(text, sizeof text, stringLeft5, dteditFunction);
                strcat(string, text);
            }
            else
            {
                switch(dteditButtonLeft)
                {
                    case 1:
                        strcat(string, stringLeft1);

                    case 2:
                        strcat(string, stringLeft2);

                    case 3:
                        strcat(string, stringLeft3);

                    default:
                    {
                        if(dteditStringLeft[0] == EOS)
                            strcat(string, stringLeft3);
                        else
                        {
                            new text[(sizeof stringLeft4+MAX_DIALOG_NAME)];

                            format(text, sizeof text, stringLeft4, dteditStringLeft);
                            strcat(string, text);
                        }
                    }
                }
            }
        }


        strcat(string, stringEnd);


        new name[(sizeof exportDialogTree+MAX_DIALOG_NAME)];

        format(name, sizeof name, exportDialogTree, dteditFunction);
        

        new File:file = fopen(name, io_append);

        fwrite(file, string);

        fclose(file);


        return ExportFunction(playerid);
    }

    static stock ExportFunction(playerid)
    {
        static const stringStyle[] =
                                    "DialogFunction:%s(playerid)\n\
                                    {\n    \
                                    //\n\n    \
                                    return UpdateDialogStyle(playerid, DIALOG_STYLE_);\n\
                                    }";

        static const stringFunction[] =
                                    "DialogFunction:%s(playerid)\n\
                                    {\n    \
                                    new string[%s];\n\n    \
                                    //\n\n    \
                                    return %s(playerid, string);\n\
                                    }";


        static const stringCaptionSize[] =
                                    "SIZE_DIALOG_CAPTION";

        static const stringInfoSize[] =
                                    "SIZE_DIALOG_INFO";

        static const stringButtonSize[] =
                                    "SIZE_DIALOG_BUTTON";


        static const stringCaptionFunction[] =
                                    "UpdateDialogCaption";

        static const stringInfoFunction[] =
                                    "UpdateDialogInfo";

        static const stringLeftFunction[] =
                                    "UpdateDialogLeft";

        static const stringRightFunction[] =
                                    "UpdateDialogRight";


        static string[750];

        if(dteditStyleFunction[0] != EOS)
        {
            new text[(sizeof stringStyle+MAX_DIALOG_NAME)];

            format(text, sizeof text, stringStyle, dteditStyleFunction);
            
            strcat(string, text);
            strcat(string, "\n\n");
        }


        if(dteditCaptionFunction[0] != EOS)
        {
            new text[(sizeof stringFunction+sizeof stringCaptionSize+sizeof stringCaptionFunction+MAX_DIALOG_NAME)];

            format(text, sizeof text, stringFunction, dteditCaptionFunction, stringCaptionSize, stringCaptionFunction);

            strcat(string, text);
            strcat(string, "\n\n");
        }


        if(dteditInfoFunction[0] != EOS)
        {
            new text[(sizeof stringFunction+sizeof stringInfoSize+sizeof stringInfoFunction+MAX_DIALOG_NAME)];

            format(text, sizeof text, stringFunction, dteditInfoFunction, stringInfoSize, stringInfoFunction);

            strcat(string, text);
            strcat(string, "\n\n");
        }


        if(dteditLeftFunction[0] != EOS)
        {
            new text[(sizeof stringFunction+sizeof stringButtonSize+sizeof stringLeftFunction+MAX_DIALOG_NAME)];

            format(text, sizeof text, stringFunction, dteditLeftFunction, stringButtonSize, stringLeftFunction);

            strcat(string, text);
            strcat(string, "\n\n");
        }


        if(dteditRightFunction[0] != EOS)
        {
            new text[(sizeof stringFunction+sizeof stringButtonSize+sizeof stringRightFunction+MAX_DIALOG_NAME)];

            format(text, sizeof text, stringFunction, dteditRightFunction, stringButtonSize, stringRightFunction);

            strcat(string, text);
        }


        new name[(sizeof exportDialogTree+MAX_DIALOG_NAME)];

        format(name, sizeof name, exportDialogTree, dteditFunction);
        

        new File:file = fopen(name, io_append);

        fwrite(file, string);

        fclose(file);


        static const stringMessage[] = "{ff0000}[DialogTree]{ffffff} Экспортировано в scriptfiles/%s";
        new message[MAX_CHATBUBBLE_LENGTH];

        format(message, sizeof message, stringMessage, name);

        SendClientMessage(playerid, -1, message);


        dteditMode = false;
        dteditView = false;

        return DTE@Clear();
    }


    DialogFunction:DTE_Name(playerid)
    {
        new string[SIZE_DIALOG_CAPTION + MAX_DIALOG_COLOR];

        strcat(string, "{ffffff}");
        strcat(string, dteditFunction);


        return UpdateDialogCaption(playerid, string);
    }

    DialogFunction:DTE_Setting(playerid)
    {
        new string[SIZE_DIALOG_INFO];

        if((dteditStyle != INVALID_DIALOG_ID || dteditStyleFunction[0] != EOS) &&
           (dteditCaption[0] != EOS || dteditCaptionFunction[0] != EOS) &&
           (dteditInfo[0] != EOS || dteditInfoFunction[0] != EOS) &&
           (dteditLeft[0] != EOS || dteditLeftFunction[0] != EOS))
            strcat(string, "{ffffff}Настроить связь\n{ffffff}Выбрать стиль\n{ffffff}Указать название\n{ffffff}Указать информацию\n{ffffff}Указать левую кнопку\n{ffffff}Указать правую кнопку\n{ffffff}Действия кнопок\n{ff0000}Экспортировать\n{00ff00}Предпросмотр");
        else
            strcat(string, "{ffffff}Настроить связь\n{ffffff}Выбрать стиль\n{ffffff}Указать название\n{ffffff}Указать информацию\n{ffffff}Указать левую кнопку\n{ffffff}Указать правую кнопку\n{ffffff}Действия кнопок\n{ff0000}Экспортировать");


        return UpdateDialogInfo(playerid, string);
    }

    DialogFunction:DTE_StyleLink(playerid)
    {
        if(dteditReferral[0] == EOS)
            return UpdateDialogStyle(playerid, DIALOG_STYLE_LIST);
        else
            return UpdateDialogStyle(playerid, DIALOG_STYLE_TABLIST_HEADERS);
    }

    DialogFunction:DTE_InfoLink(playerid)
    {
        new string[SIZE_DIALOG_INFO];

        if(dteditReferral[0] == EOS)
            strcat(string, "{ffffff}Указать родительский элемент");
        else
            format(string, sizeof string, "{ff0000}%s\n{ffffff}Изменить родительский элемент\n{ffffff}Удалить родительский элемент", dteditReferral);


        return UpdateDialogInfo(playerid, string);
    }

    DialogFunction:DTE_StyleStyle(playerid)
    {
        if(dteditStyle == INVALID_DIALOG_ID && dteditStyleFunction[0] == EOS)
            return UpdateDialogStyle(playerid, DIALOG_STYLE_LIST);
        else
            return UpdateDialogStyle(playerid, DIALOG_STYLE_TABLIST_HEADERS);
    }

    DialogFunction:DTE_InfoStyle(playerid)
    {
        new string[SIZE_DIALOG_INFO];

        if(dteditStyle == INVALID_DIALOG_ID)
            strcat(string, "{ffffff}Установить значение по умолчанию\n{ffffff}Установить значение функции");
        else
        {
            new text[(30+3+1)];

            if(dteditStyle == DIALOG_STYLE_MSGBOX)
                strcat(text, "DIALOG_STYLE_MSGBOX");

            else if(dteditStyle == DIALOG_STYLE_INPUT)
                strcat(text, "DIALOG_STYLE_INPUT");

            else if(dteditStyle == DIALOG_STYLE_LIST)
                strcat(text, "DIALOG_STYLE_LIST");

            else if(dteditStyle == DIALOG_STYLE_PASSWORD)
                strcat(text, "DIALOG_STYLE_PASSWORD");

            else if(dteditStyle == DIALOG_STYLE_TABLIST)
                strcat(text, "DIALOG_STYLE_TABLIST");

            else if(dteditStyle == DIALOG_STYLE_TABLIST_HEADERS)
                strcat(text, "DIALOG_STYLE_TABLIST_HEADERS");

            else if(DLG_STYLE_BOOK <= dteditStyle && dteditStyle < DLG_STYLE_TABBOOK)
                format(text, sizeof text, "DIALOG_STYLE_BOOK<%i>", (dteditStyle/DLG_STYLE_BOOK));

            else if(DLG_STYLE_TABBOOK <= dteditStyle && dteditStyle < DLG_STYLE_TABBOOK_HEADERS)
                format(text, sizeof text, "DIALOG_STYLE_TABBOOK<%i>", (dteditStyle/DLG_STYLE_TABBOOK));

            else if(DLG_STYLE_TABBOOK_HEADERS <= dteditStyle)
                format(text, sizeof text, "DIALOG_STYLE_TABBOOK_HEADERS<%i>", (dteditStyle/DLG_STYLE_TABBOOK_HEADERS));


            format(string, sizeof string, "{ff0000}%s\n{ffffff}Изменить значение по умолчанию\n{ffffff}Установить значение функции", text);
        }


        if(dteditStyleFunction[0] != EOS)
        {
            if(dteditStyle == INVALID_DIALOG_ID)
                format(string, sizeof string, "{ff0000}%s\n{ffffff}Установить значение по умолчанию\n{ffffff}Изменить значение функции", dteditStyleFunction);
            else
                format(string, sizeof string, "{ff0000}%s\n{ffffff}Изменить значение по умолчанию\n{ffffff}Изменить значение функции", dteditStyleFunction);       
        }


        return UpdateDialogInfo(playerid, string);
    }

    DialogFunction:DTE_StyleCaption(playerid)
    {
        if(dteditCaption[0] == EOS && dteditCaptionFunction[0] == EOS)
            return UpdateDialogStyle(playerid, DIALOG_STYLE_LIST);
        else
            return UpdateDialogStyle(playerid, DIALOG_STYLE_TABLIST_HEADERS);
    }

    DialogFunction:DTE_InfoCaption(playerid)
    {
        new string[SIZE_DIALOG_INFO];

        if(dteditCaption[0] == EOS)
            strcat(string, "{ffffff}Установить значение по умолчанию\n{ffffff}Установить значение функции");
        else
        {
            new text[(SIZE_DIALOG_CAPTION/2)];

            strcat(text, dteditCaption);

            if(strlen(dteditCaption) > (SIZE_DIALOG_CAPTION/2))
                format(string, sizeof string, "{%s}%s...\n{ffffff}Изменить значение по умолчанию\n{ffffff}Установить значение функции\nЗадать цвет строки", (dteditCaptionColor[0] == EOS) ? ("ff0000") : (dteditCaptionColor), text);
            else
                format(string, sizeof string, "{%s}%s\n{ffffff}Изменить значение по умолчанию\n{ffffff}Установить значение функции\nЗадать цвет строки", (dteditCaptionColor[0] == EOS) ? ("ff0000") : (dteditCaptionColor), text);
        }


        if(dteditCaptionFunction[0] != EOS)
        {
            if(dteditCaption[0] == EOS)
                format(string, sizeof string, "{ff0000}%s\n{ffffff}Установить значение по умолчанию\n{ffffff}Изменить значение функции", dteditCaptionFunction);
            else
                format(string, sizeof string, "{ff0000}%s\n{ffffff}Изменить значение по умолчанию\n{ffffff}Изменить значение функции\nЗадать цвет строки", dteditCaptionFunction);       
        }


        return UpdateDialogInfo(playerid, string);
    }

    DialogFunction:DTE_StyleInfo(playerid)
    {
        if(dteditInfo[0] == EOS && dteditInfoFunction[0] == EOS)
            return UpdateDialogStyle(playerid, DIALOG_STYLE_LIST);
        else
            return UpdateDialogStyle(playerid, DIALOG_STYLE_TABLIST_HEADERS);
    }

    DialogFunction:DTE_InfoInfo(playerid)
    {
        new string[SIZE_DIALOG_INFO];

        if(dteditInfo[0] == EOS)
            strcat(string, "{ffffff}Установить значение по умолчанию\n{ffffff}Установить значение функции");
        else
        {
            new text[(SIZE_DIALOG_CAPTION/2)];

            strcat(text, dteditInfo);

            if(strlen(dteditInfo) > (SIZE_DIALOG_CAPTION/2))
                format(string, sizeof string, "{%s}%s...\n{ffffff}Изменить значение по умолчанию\n{ffffff}Установить значение функции\nЗадать цвет строки", (dteditInfoColor[0] == EOS) ? ("ff0000") : (dteditInfoColor), text);
            else
                format(string, sizeof string, "{%s}%s\n{ffffff}Изменить значение по умолчанию\n{ffffff}Установить значение функции\nЗадать цвет строки", (dteditInfoColor[0] == EOS) ? ("ff0000") : (dteditInfoColor), text);
        }


        if(dteditInfoFunction[0] != EOS)
        {
            if(dteditInfo[0] == EOS)
                format(string, sizeof string, "{ff0000}%s\n{ffffff}Установить значение по умолчанию\n{ffffff}Изменить значение функции", dteditInfoFunction);
            else
                format(string, sizeof string, "{ff0000}%s\n{ffffff}Изменить значение по умолчанию\n{ffffff}Изменить значение функции\nЗадать цвет строки", dteditInfoFunction);       
        }


        return UpdateDialogInfo(playerid, string);
    }

    DialogFunction:DTE_StyleLeft(playerid)
    {
        if(dteditLeft[0] == EOS && dteditLeftFunction[0] == EOS)
            return UpdateDialogStyle(playerid, DIALOG_STYLE_LIST);
        else
            return UpdateDialogStyle(playerid, DIALOG_STYLE_TABLIST_HEADERS);
    }

    DialogFunction:DTE_InfoLeft(playerid)
    {
        new string[SIZE_DIALOG_INFO];

        if(dteditLeft[0] == EOS)
            strcat(string, "{ffffff}Установить значение по умолчанию\n{ffffff}Установить значение функции");
        else
            format(string, sizeof string, "{%s}%s\n{ffffff}Изменить значение по умолчанию\n{ffffff}Установить значение функции\nЗадать цвет строки", (dteditLeftColor[0] == EOS) ? ("ff0000") : (dteditLeftColor), dteditLeft);


        if(dteditLeftFunction[0] != EOS)
        {
            if(dteditLeft[0] == EOS)
                format(string, sizeof string, "{ff0000}%s\n{ffffff}Установить значение по умолчанию\n{ffffff}Изменить значение функции", dteditLeftFunction);
            else
                format(string, sizeof string, "{ff0000}%s\n{ffffff}Изменить значение по умолчанию\n{ffffff}Изменить значение функции\nЗадать цвет строки", dteditLeftFunction);       
        }


        return UpdateDialogInfo(playerid, string);
    }

    DialogFunction:DTE_StyleRight(playerid)
    {
        if(dteditRight[0] == EOS && dteditRightFunction[0] == EOS)
            return UpdateDialogStyle(playerid, DIALOG_STYLE_LIST);
        else
            return UpdateDialogStyle(playerid, DIALOG_STYLE_TABLIST_HEADERS);
    }

    DialogFunction:DTE_InfoRight(playerid)
    {
        new string[SIZE_DIALOG_INFO];

        if(dteditRight[0] == EOS)
            strcat(string, "{ffffff}Установить значение по умолчанию\n{ffffff}Установить значение функции");
        else
            format(string, sizeof string, "{%s}%s\n{ffffff}Изменить значение по умолчанию\n{ffffff}Установить значение функции\nЗадать цвет строки", (dteditRightColor[0] == EOS) ? ("ff0000") : (dteditRightColor), dteditRight);


        if(dteditRightFunction[0] != EOS)
        {
            if(dteditRight[0] == EOS)
                format(string, sizeof string, "{ff0000}%s\n{ffffff}Установить значение по умолчанию\n{ffffff}Изменить значение функции", dteditRightFunction);
            else
                format(string, sizeof string, "{ff0000}%s\n{ffffff}Изменить значение по умолчанию\n{ffffff}Изменить значение функции\nЗадать цвет строки", dteditRightFunction);       
        }


        return UpdateDialogInfo(playerid, string);
    }

    DialogFunction:DTE_Button(playerid)
    {
        new string[SIZE_DIALOG_INFO],
            left[SIZE_DIALOG_BUTTON],
            right[SIZE_DIALOG_BUTTON];


        if(dteditButtonLeft != INVALID_DIALOG_ID)
        {
            switch(dteditButtonLeft)
            {
                case 1:
                    strcat(left, "Перейти на предыдущий");

                case 2:
                    strcat(left, "Закрыть");

                default:
                {
                    if(dteditStringLeft[0] == EOS)
                        strcat(left, "Перейти на следующий");
                    else
                        format(left, sizeof left, "Перейти на следующий (%s)", dteditStringLeft);
                }
            }
        }

        if(dteditButtonRight != INVALID_DIALOG_ID)
        {
            switch(dteditButtonRight)
            {
                case 1:
                    strcat(right, "Перейти на предыдущий");

                case 2:
                    strcat(right, "Закрыть");

                case 3:
                    strcat(right, "Другое");

                default:
                {
                    if(dteditStringRight[0] == EOS)
                        strcat(right, "Перейти на следующий");
                    else
                        format(right, sizeof left, "Перейти на следующий (%s)", dteditStringRight);
                }
            }
        }


        format(string, sizeof string, "{ffffff}Левая кнопка\t{ff0000}%s\n{ffffff}Правая кнопка\t{ff0000}%s", left, right);


        return UpdateDialogInfo(playerid, string);
    }


    OnDialog:DTE@Create(playerid)
    {
        if(IsDialogResponseRight())
        {
            dteditMode = false;

            return ClosePlayerDialog(playerid);
        }


        new len = strlen(GetDialogInputtext());


        if(!len)
            return OpenPlayerDialog(playerid);


        if(len > MAX_DIALOG_NAME)
        {
            SendClientMessage(playerid, -1, "{ff0000}[DialogTree]{ffffff} Название диалога превышает допустимую длину");

            return OpenPlayerDialog(playerid);
        }


        new name[(11+SIZE_DIALOG_NAME+3+1)];

        format(name, sizeof name, "DialogTree_%s.txt", GetDialogInputtext());

        if(fexist(name))
        {
            SendClientMessage(playerid, -1, "{ff0000}[DialogTree]{ffffff} Файл с таким именем уже существует");

            return OpenPlayerDialog(playerid);
        }


        DTE@Clear();


        strcat(dteditFunction, GetDialogInputtext());


        return OpenPlayerDialog(playerid, Dialog:DTE@Setting);
    }

    OnDialog:DTE@Setting(playerid)
    {
        if(IsDialogResponseRight())
            return OpenPlayerDialog(playerid, Dialog:DTE@Exit);


        if(GetDialogListitem() == 7)
        {
            dteditMode = false;

            return DTE@ExportCreate(playerid);
        }

        else if(GetDialogListitem() == 8)
        {
            ClosePlayerDialog(playerid);


            dteditMode = false;
            dteditView = true;


            new style,
                caption[SIZE_DIALOG_CAPTION],
                info[SIZE_DIALOG_INFO],
                left[SIZE_DIALOG_BUTTON],
                right[SIZE_DIALOG_BUTTON];


            #if !defined DIALOG_TREE_WITHOUT_BOOK

                if(dteditStyleFunction[0] != EOS)
                    style = DIALOG_STYLE_MSGBOX;
                else
                {
                    if(dteditStyle < DLG_STYLE_BOOK)
                        style = dteditStyle;

                    else if(DLG_STYLE_BOOK <= dteditStyle && dteditStyle < DLG_STYLE_TABBOOK)
                        style = DIALOG_STYLE_LIST;

                    else if(DLG_STYLE_TABBOOK <= dteditStyle && dteditStyle < DLG_STYLE_TABBOOK_HEADERS)
                        style = DIALOG_STYLE_TABLIST;

                    else if(DLG_STYLE_TABBOOK_HEADERS <= dteditStyle)
                        style = DIALOG_STYLE_TABLIST_HEADERS;
                }

            #else

                if(dteditStyleFunction[0] != EOS)
                    style = DIALOG_STYLE_MSGBOX;
                else
                    style = dteditStyle;

            #endif


            if(dteditCaptionFunction[0] != EOS)
                strcat(caption, dteditCaptionFunction);
            else
            {
                if(dteditCaptionColor[0] != EOS)
                {
                    strcat(caption, "{");
                    strcat(caption, dteditCaptionColor);
                    strcat(caption, "}");
                }

                strcat(caption, dteditCaption);
            }


            if(dteditInfoFunction[0] != EOS)
                strcat(info, dteditInfoFunction);
            else
            {
                if(dteditInfoColor[0] != EOS)
                {
                    strcat(info, "{");
                    strcat(info, dteditInfoColor);
                    strcat(info, "}");
                }


                new row = 1,
                    maxRow;

                if(DLG_STYLE_BOOK <= dteditStyle && dteditStyle < DLG_STYLE_TABBOOK)
                    maxRow = (dteditStyle/DLG_STYLE_BOOK);

                else if(DLG_STYLE_TABBOOK <= dteditStyle && dteditStyle < DLG_STYLE_TABBOOK_HEADERS)
                    maxRow = (dteditStyle/DLG_STYLE_TABBOOK);

                else if(DLG_STYLE_TABBOOK_HEADERS <= dteditStyle)
                    maxRow = (dteditStyle/DLG_STYLE_TABBOOK_HEADERS);


                for(new i = 0, j = strlen(info), len = strlen(dteditInfo); i < len; i++)
                {
                    if(dteditInfo[i] == '\\' && dteditInfo[(i+1)] == 'n')
                    {
                        info[j] = '\n';

                        row++;
                        i++;

                        if(maxRow != 0 && row > maxRow)
                            break;
                    }
                    else if(dteditInfo[i] == '\\' && dteditInfo[(i+1)] == 't')
                    {
                        info[j] = '\t';

                        i++;
                    }
                    else
                        info[j] = dteditInfo[i];


                    j++;
                }


                if(maxRow != 0 && row > maxRow)
                    format(info, sizeof info, "%s\n%c", info, DIALOG_ARROW_RIGHT);
            }


            if(dteditLeftFunction[0] != EOS)
                strcat(left, dteditLeftFunction);
            else
            {
                if(dteditLeftColor[0] != EOS)
                {
                    strcat(left, "{");
                    strcat(left, dteditLeftColor);
                    strcat(left, "}");
                }
                
                strcat(left, dteditLeft);
            }


            if(dteditRightFunction[0] != EOS)
                strcat(right, dteditRightFunction);
            else
            {
                if(dteditRightColor[0] != EOS)
                {
                    strcat(right, "{");
                    strcat(right, dteditRightColor);
                    strcat(right, "}");
                }
                
                strcat(right, dteditRight);
            }


            return ShowPlayerDialog(playerid, DIALOG_ID, style, caption, info, left, right);
        }

        else
        {
            #if defined DIALOG_TREE_WITHOUT_ARRAY

                return OpenNextPlayerDialog(playerid, GetDialogReferral(Dialog:DTE@Setting, GetDialogListitem()));

            #else

                new dialog[SIZE_DIALOG_NAME];

                GetDialogReferral(Dialog:DTE@Setting, GetDialogListitem(), dialog);

                return OpenNextPlayerDialog(playerid, dialog);

            #endif
        }
    }

    OnDialog:DTE@Exit(playerid)
    {
        if(IsDialogResponseRight())
            return OpenPlayerDialog(playerid, Dialog:DTE@Setting);


        DTE@Clear();

        dteditMode = false;


        return ClosePlayerDialog(playerid);
    }

    OnDialog:DTE@Link(playerid)
    {
        if(IsDialogResponseRight())
            return OpenBackPlayerDialog(playerid);


        #if defined DIALOG_TREE_WITHOUT_ARRAY

            return OpenNextPlayerDialog(playerid, GetDialogReferral(Dialog:DTE@Link, GetDialogListitem()));

        #else

            new dialog[SIZE_DIALOG_NAME];

            GetDialogReferral(Dialog:DTE@Link, GetDialogListitem(), dialog);

            return OpenNextPlayerDialog(playerid, dialog);

        #endif
    }

    OnDialog:DTE@LinkNew(playerid)
    {
        if(IsDialogResponseLeft())
        {
            if(!strlen(GetDialogInputtext()))
                return OpenPlayerDialog(playerid);


            strcat((dteditReferral[0] = EOS, dteditReferral), GetDialogInputtext());
        }


        return OpenBackPlayerDialog(playerid);
    }

    OnDialog:DTE@LinkDelete(playerid)
    {
        if(IsDialogResponseLeft())
            dteditReferral[0] = EOS;


        return OpenBackPlayerDialog(playerid);
    }

    OnDialog:DTE@Style(playerid)
    {
        if(IsDialogResponseRight())
            return OpenBackPlayerDialog(playerid);


        #if defined DIALOG_TREE_WITHOUT_ARRAY

            return OpenNextPlayerDialog(playerid, GetDialogReferral(Dialog:DTE@Style, GetDialogListitem()));

        #else

            new dialog[SIZE_DIALOG_NAME];

            GetDialogReferral(Dialog:DTE@Style, GetDialogListitem(), dialog);

            return OpenNextPlayerDialog(playerid, dialog);

        #endif
    }

    OnDialog:DTE@StyleDefault(playerid)
    {
        if(IsDialogResponseLeft())
        {
            if(GetDialogListitem() < 6)
                dteditStyle = GetDialogListitem();
            else
            {
                if(GetDialogListitem() == 6)
                    dteditStyle = DLG_STYLE_BOOK;

                else if(GetDialogListitem() == 7)
                    dteditStyle = DLG_STYLE_TABBOOK;

                else if(GetDialogListitem() == 8)
                    dteditStyle = DLG_STYLE_TABBOOK_HEADERS;
                

                return OpenPlayerDialog(playerid, Dialog:DTE@StylePage);
            }
        }


        return OpenBackPlayerDialog(playerid);
    }

    OnDialog:DTE@StyleFunction(playerid)
    {
        if(IsDialogResponseLeft())
        {
            if(strlen(GetDialogInputtext()) > MAX_DIALOG_NAME)
            {
                SendClientMessage(playerid, -1, "{ff0000}[DialogTree]{ffffff} Название функции превышает допустимую длину");

                return OpenPlayerDialog(playerid);
            }


            strcat((dteditStyleFunction[0] = EOS, dteditStyleFunction), GetDialogInputtext());
        }   


        return OpenBackPlayerDialog(playerid);
    }

    OnDialog:DTE@StylePage(playerid)
    {
        if(IsDialogResponseRight())
            dteditStyle = INVALID_DIALOG_ID;
        else
        {
            new len = strlen(GetDialogInputtext());

            if(!len)
                return OpenPlayerDialog(playerid);


            for(new i = 0; i < len; i++)
            {
                switch(GetDialogInputtext()[i])
                {
                    case '0'..'9':
                        continue;

                    default:
                    {
                        SendClientMessage(playerid, -1, "{ff0000}[DialogTree]{ffffff} Вы указали недействительное количество строк");

                        return OpenPlayerDialog(playerid);
                    }
                }
            }


            new row = strval(GetDialogInputtext());

            if(row < 1)
            {
                SendClientMessage(playerid, -1, "{ff0000}[DialogTree]{ffffff} Вы указали недействительное количество строк");

                return OpenPlayerDialog(playerid);
            }


            dteditStyle *= row;
        }


        return OpenBackPlayerDialog(playerid);
    }

    OnDialog:DTE@Caption(playerid)
    {
        if(IsDialogResponseRight())
            return OpenBackPlayerDialog(playerid);


        #if defined DIALOG_TREE_WITHOUT_ARRAY

            return OpenNextPlayerDialog(playerid, GetDialogReferral(Dialog:DTE@Caption, GetDialogListitem()));

        #else

            new dialog[SIZE_DIALOG_NAME];

            GetDialogReferral(Dialog:DTE@Caption, GetDialogListitem(), dialog);

            return OpenNextPlayerDialog(playerid, dialog);

        #endif
    }

    OnDialog:DTE@CaptionDefault(playerid)
    {
        if(IsDialogResponseLeft())
        {
            new len = strlen(GetDialogInputtext());

            if(!len)
                return OpenPlayerDialog(playerid);


            if(len > MAX_DIALOG_CAPTION)
            {
                SendClientMessage(playerid, -1, "{ff0000}[DialogTree]{ffffff} Название превышает допустимую длину");

                return OpenPlayerDialog(playerid);
            }


            strcat((dteditCaption[0] = EOS, dteditCaption), GetDialogInputtext());
        }


        return OpenBackPlayerDialog(playerid);
    }

    OnDialog:DTE@CaptionFunction(playerid)
    {
        if(IsDialogResponseLeft())
        {
            if(strlen(GetDialogInputtext()) > MAX_DIALOG_NAME)
            {
                SendClientMessage(playerid, -1, "{ff0000}[DialogTree]{ffffff} Название функции превышает допустимую длину");

                return OpenPlayerDialog(playerid);
            }


            strcat((dteditCaptionFunction[0] = EOS, dteditCaptionFunction), GetDialogInputtext());
        }


        return OpenBackPlayerDialog(playerid);
    }

    OnDialog:DTE@CaptionColor(playerid)
    {
        if(IsDialogResponseLeft())
        {
            new len = strlen(GetDialogInputtext());

            if(!len)
                dteditCaptionColor[0] = EOS;

            else if(strlen(GetDialogInputtext()) != 6)
            {
                SendClientMessage(playerid, -1, "{ff0000}[DialogTree]{ffffff} Цвет превышает допустимую длину");

                return OpenPlayerDialog(playerid);
            }


            if(!DTE@IsHex(GetDialogInputtext()))
            {
                SendClientMessage(playerid, -1, "{ff0000}[DialogTree]{ffffff} Вы указали недействительный цвет");

                return OpenPlayerDialog(playerid);
            }


            strcat((dteditCaptionColor[0] = EOS, dteditCaptionColor), GetDialogInputtext());
        }


        return OpenBackPlayerDialog(playerid);
    }

    OnDialog:DTE@Info(playerid)
    {
        if(IsDialogResponseRight())
            return OpenBackPlayerDialog(playerid);


        #if defined DIALOG_TREE_WITHOUT_ARRAY

            return OpenNextPlayerDialog(playerid, GetDialogReferral(Dialog:DTE@Info, GetDialogListitem()));

        #else

            new dialog[SIZE_DIALOG_NAME];

            GetDialogReferral(Dialog:DTE@Info, GetDialogListitem(), dialog);

            return OpenNextPlayerDialog(playerid, dialog);

        #endif
    }

    OnDialog:DTE@InfoDefault(playerid)
    {
        if(IsDialogResponseLeft())
        {
            new len = strlen(GetDialogInputtext());

            if(!len)
                return OpenPlayerDialog(playerid);


            if(len > MAX_DIALOG_INFO)
            {
                SendClientMessage(playerid, -1, "{ff0000}[DialogTree]{ffffff} Информация превышает допустимую длину");

                return OpenPlayerDialog(playerid);
            }


            strcat((dteditInfo[0] = EOS, dteditInfo), GetDialogInputtext());
        }


        return OpenBackPlayerDialog(playerid);
    }

    OnDialog:DTE@InfoFunction(playerid)
    {
        if(IsDialogResponseLeft())
        {
            if(strlen(GetDialogInputtext()) > MAX_DIALOG_NAME)
            {
                SendClientMessage(playerid, -1, "{ff0000}[DialogTree]{ffffff} Название функции превышает допустимую длину");

                return OpenPlayerDialog(playerid);
            }


            strcat((dteditInfoFunction[0] = EOS, dteditInfoFunction), GetDialogInputtext());
        }


        return OpenBackPlayerDialog(playerid);
    }

    OnDialog:DTE@InfoColor(playerid)
    {
        if(IsDialogResponseLeft())
        {
            new len = strlen(GetDialogInputtext());

            if(!len)
                dteditInfoColor[0] = EOS;

            else if(strlen(GetDialogInputtext()) != 6)
            {
                SendClientMessage(playerid, -1, "{ff0000}[DialogTree]{ffffff} Цвет превышает допустимую длину");

                return OpenPlayerDialog(playerid);
            }


            if(!DTE@IsHex(GetDialogInputtext()))
            {
                SendClientMessage(playerid, -1, "{ff0000}[DialogTree]{ffffff} Вы указали недействительный цввет");

                return OpenPlayerDialog(playerid);
            }


            strcat((dteditInfoColor[0] = EOS, dteditInfoColor), GetDialogInputtext());
        }


        return OpenBackPlayerDialog(playerid);
    }

    OnDialog:DTE@Left(playerid)
    {
        if(IsDialogResponseRight())
            return OpenBackPlayerDialog(playerid);


        #if defined DIALOG_TREE_WITHOUT_ARRAY

            return OpenNextPlayerDialog(playerid, GetDialogReferral(Dialog:DTE@Left, GetDialogListitem()));

        #else

            new dialog[SIZE_DIALOG_NAME];

            GetDialogReferral(Dialog:DTE@Left, GetDialogListitem(), dialog);

            return OpenNextPlayerDialog(playerid, dialog);

        #endif
    }

    OnDialog:DTE@LeftDefault(playerid)
    {
        if(IsDialogResponseLeft())
        {
            new len = strlen(GetDialogInputtext());

            if(!len)
                return OpenPlayerDialog(playerid);


            if(len > MAX_DIALOG_BUTTON)
            {
                SendClientMessage(playerid, -1, "{ff0000}[DialogTree]{ffffff} Кнопка превышает допустимую длину");

                return OpenPlayerDialog(playerid);
            }


            strcat((dteditLeft[0] = EOS, dteditLeft), GetDialogInputtext());
        }


        return OpenBackPlayerDialog(playerid);
    }

    OnDialog:DTE@LeftFunction(playerid)
    {
        if(IsDialogResponseLeft())
        {
            if(strlen(GetDialogInputtext()) > MAX_DIALOG_NAME)
            {
                SendClientMessage(playerid, -1, "{ff0000}[DialogTree]{ffffff} Название функции превышает допустимую длину");

                return OpenPlayerDialog(playerid);
            }


            strcat((dteditLeftFunction[0] = EOS, dteditLeftFunction), GetDialogInputtext());
        }


        return OpenBackPlayerDialog(playerid);
    }

    OnDialog:DTE@LeftColor(playerid)
    {
        if(IsDialogResponseLeft())
        {
            new len = strlen(GetDialogInputtext());

            if(!len)
                dteditLeftColor[0] = EOS;

            else if(strlen(GetDialogInputtext()) != 6)
            {
                SendClientMessage(playerid, -1, "{ff0000}[DialogTree]{ffffff} Цвет превышает допустимую длину");

                return OpenPlayerDialog(playerid);
            }


            if(!DTE@IsHex(GetDialogInputtext()))
            {
                SendClientMessage(playerid, -1, "{ff0000}[DialogTree]{ffffff} Вы указали недействительный цввет");

                return OpenPlayerDialog(playerid);
            }


            strcat((dteditLeftColor[0] = EOS, dteditLeftColor), GetDialogInputtext());
        }


        return OpenBackPlayerDialog(playerid);
    }

    OnDialog:DTE@Right(playerid)
    {
        if(IsDialogResponseRight())
            return OpenBackPlayerDialog(playerid);


        #if defined DIALOG_TREE_WITHOUT_ARRAY

            return OpenNextPlayerDialog(playerid, GetDialogReferral(Dialog:DTE@Right, GetDialogListitem()));

        #else

            new dialog[SIZE_DIALOG_NAME];

            GetDialogReferral(Dialog:DTE@Right, GetDialogListitem(), dialog);

            return OpenNextPlayerDialog(playerid, dialog);

        #endif
    }

    OnDialog:DTE@RightDefault(playerid)
    {
        if(IsDialogResponseLeft())
        {
            if(strlen(GetDialogInputtext()) > MAX_DIALOG_BUTTON)
            {
                SendClientMessage(playerid, -1, "{ff0000}[DialogTree]{ffffff} Кнопка превышает допустимую длину");

                return OpenPlayerDialog(playerid);
            }


            strcat((dteditRight[0] = EOS, dteditRight), GetDialogInputtext());
        }


        return OpenBackPlayerDialog(playerid);
    }

    OnDialog:DTE@RightFunction(playerid)
    {
        if(IsDialogResponseLeft())
        {
            if(strlen(GetDialogInputtext()) > MAX_DIALOG_NAME)
            {
                SendClientMessage(playerid, -1, "{ff0000}[DialogTree]{ffffff} Название функции превышает допустимую длину");

                return OpenPlayerDialog(playerid);
            }


            strcat((dteditRightFunction[0] = EOS, dteditRightFunction), GetDialogInputtext());
        }


        return OpenBackPlayerDialog(playerid);
    }

    OnDialog:DTE@RightColor(playerid)
    {
        if(IsDialogResponseLeft())
        {
            new len = strlen(GetDialogInputtext());

            if(!len)
                dteditRightColor[0] = EOS;

            else if(strlen(GetDialogInputtext()) != 6)
            {
                SendClientMessage(playerid, -1, "{ff0000}[DialogTree]{ffffff} Цвет превышает допустимую длину");

                return OpenPlayerDialog(playerid);
            }


            if(!DTE@IsHex(GetDialogInputtext()))
            {
                SendClientMessage(playerid, -1, "{ff0000}[DialogTree]{ffffff} Вы указали недействительный цввет");

                return OpenPlayerDialog(playerid);
            }


            strcat((dteditRightColor[0] = EOS, dteditRightColor), GetDialogInputtext());
        }


        return OpenBackPlayerDialog(playerid);
    }

    OnDialog:DTE@Button(playerid)
    {
        if(IsDialogResponseRight())
            return OpenBackPlayerDialog(playerid);


        #if defined DIALOG_TREE_WITHOUT_ARRAY

            return OpenNextPlayerDialog(playerid, GetDialogReferral(Dialog:DTE@Button, GetDialogListitem()));

        #else

            new dialog[SIZE_DIALOG_NAME];

            GetDialogReferral(Dialog:DTE@Button, GetDialogListitem(), dialog);

            return OpenNextPlayerDialog(playerid, dialog);

        #endif
    }

    OnDialog:DTE@ButtonLeft(playerid)
    {
        if(IsDialogResponseLeft())
        {
            dteditButtonLeft = GetDialogListitem();


            if(GetDialogListitem() == 0)
                return OpenNextPlayerDialog(playerid);
        }
            

        return OpenBackPlayerDialog(playerid);
    }

    OnDialog:DTE@ButtonRight(playerid)
    {
        if(IsDialogResponseLeft())
        {
            if(GetDialogListitem() == 0)
                dteditButtonRight = 1;

            else if(GetDialogListitem() == 1)
                dteditButtonRight = 0;

            else
                dteditButtonRight = GetDialogListitem();


            if(GetDialogListitem() == 1)
                return OpenNextPlayerDialog(playerid);
        }


        return OpenBackPlayerDialog(playerid);
    }

    OnDialog:DTE@ButtonLeftInput(playerid)
    {
        if(IsDialogResponseLeft())
            strcat(dteditStringLeft, GetDialogInputtext());
        else
            dteditButtonLeft = INVALID_DIALOG_ID;


        return OpenPlayerDialog(playerid, Dialog:DTE@Button);
    }

    OnDialog:DTE@ButtonRightInput(playerid)
    {
        if(IsDialogResponseLeft())
            strcat(dteditStringRight, GetDialogInputtext());
        else
            dteditButtonRight = INVALID_DIALOG_ID;


        return OpenPlayerDialog(playerid, Dialog:DTE@Button);
    }

#endif