/**
 *
 * @author changgyu.seong
 * @date 2024.07.29
 */

let SlotBase = require( './../slotBase' );
let code = require( './../code' );
let util = require( 'util' );
let assert = require( 'assert' );
let signal = require( './../signalDefines' );
let utils = require( './../utils' );
let common = require( '../util/common' );
let number = require( '../util/number' );
let slotUtils = require( './../slotUtils' );
let reelObject = require( './reelServerObject' );
let logger = require('pomelo-logger').getLogger( 'RockNCash', __filename, process.pid );
let userDao = require('../dao/userDao');
const reelWeightObject = require("./reelWeightServerObject");
const boardObject = require("./boardServerObject");

let RabbitsTrail = function( conf ) {
    SlotBase.call( this, conf );

    this.initialize();
    this.initVariable();
};

util.inherits( RabbitsTrail, SlotBase );
module.exports = RabbitsTrail;

RabbitsTrail.prototype.initialize = function() {
    this.initParSheet();
    this.initReels();
    this.initReelsWeights();
    this.initMiniGameWeights();


};

RabbitsTrail.prototype.initParSheet = function() {
    if( !this.parSheet ) {
        return;
    }

    this.SCATTER_SYMBOL_ID = this.parSheet.scatterSymbolID;
    this.WILD_SYMBOL_IDS = this.parSheet.wildSymbolIDs;
    this.MUL_WILD_SYMBOL_IDS = this.parSheet.mulWildSymbolIDsForServer;

    this.MYSTERY_SYMBOL_IDS = this.parSheet.mysterySymbolIDs;
    this.MYSTERY_SYMBOL_CANDIDATE_IDS = this.parSheet.mysterySymbolCandidateIDs;
    this.NORMAL_MYSTERY_SYMBOL_SELECT_WEIGHT = this.parSheet.normalMysterySymbolSelectWeight;

    this.NORMAL_REEL_SELECT_WEIGHT = this.parSheet.normalReelSelectWeight;
    this.NORMAL_WEIGHT_SELECT_WEIGHT = this.parSheet.normalWeightSelectWeight;
    this.NORMAL_WEIGHT_BUFF_SELECT_WEIGHT = this.parSheet.normalWeightBuffSelectWeight;
    this.NORMAL_WEIGHT_DE_BUFF_SELECT_WEIGHT = this.parSheet.normalWeightDeBuffSelectWeight;
    this.SCATTER_MATHC_COUNT = this.parSheet.normalSpinInfoForServer.scatterMatchCount;
    this.BLANK_SYMBOL_ID = this.parSheet.normalSpinInfoForServer.blankSymbolID;

    this.BOARD_INFO = this.parSheet.boardInfo;
    this.DICE_COUNT = this.parSheet.boardInfo.diceCount;
    this.INIT_BOARD_LIST = this.parSheet.boardInfo.initBoardList;
    this.BOARD_INFO_FOR_SERVER = this.parSheet.boardInfoForServer;
    this.INIT_MINI_GAME_LEVEL = this.parSheet.boardInfoForServer.initMiniGameLevel;
    this.WHEEL_JACKPOT_INFO = this.parSheet.boardInfoForServer.wheelJackpotInfo;
    this.DICE_COMBINATION_SELECT_WEIGHT = this.parSheet.boardInfoForServer.diceInfo.diceCombinationSelectWeight;
    this.BOARD_START_LOCATION = this.parSheet.boardInfoForServer.boardStartLocation;
    this.INIT_ROLL_COUNT = this.parSheet.boardInfoForServer.initRollCount;
    this.BOARD_GAME_DATA_TYPE = this.parSheet.boardInfo.defineState;
    this.MAX_MINI_GAME_LEVEL = this.parSheet.boardInfoForServer.maxMiniGameLevel;
    this.BOARD_GAME_JACKPOT_SYMBOL_IDS = this.parSheet.boardInfoForServer.boardGameJackpotSymbolIDs;
    this.BOARD_GAME_DP_SYMBOL_IDS = this.parSheet.boardInfoForServer.boardGameDpSymbolIDs;
    this.BOARD_GAME_LOCATE_PROB_TABLE = this.parSheet.boardInfoForServer.boardGameLocateProbTable;

    this.DEFINE_BUFF_PAYBACK_STATE = {
        NORMAL : this.parSheet.boardInfoForServer.defineBuffPaybackState.normal,
        BUFF : this.parSheet.boardInfoForServer.defineBuffPaybackState.buff,
        DE_BUFF : this.parSheet.boardInfoForServer.defineBuffPaybackState.deBuff,
    }

    this.DEFAULT_BOARD_PAYBACK = this.parSheet.boardInfoForServer.defaultBoardPayback;
    this.BOARD_PAYBACK_INFO = {
        DP_PAYBACK: this.parSheet.boardInfoForServer.boardPaybackInfo.dpPayback,
        WHEEL_JACKPOT_PAYBACK: this.parSheet.boardInfoForServer.boardPaybackInfo.wheelJackpotPayback,
        MINI_GAME_PAYBACK: this.parSheet.boardInfoForServer.boardPaybackInfo.miniGamePayback
    } ;

    this.MINI_GAME_INFO = this.parSheet.miniGameInfoForServer;
    this.MINI_GAME_INIT_SPIN_COUNT = this.parSheet.miniGameInfoForServer.initSpinCount;
    this.MINI_GAME_SIZE = this.parSheet.miniGameInfoForServer.miniGameSize;
    this.MINI_GAME_INFO_1 = this.parSheet.miniGameInfoForServer.miniGameInfo1;
    this.MINI_GAME_INFO_2 = this.parSheet.miniGameInfoForServer.miniGameInfo2;
    this.MINI_GAME_INFO_3 = this.parSheet.miniGameInfoForServer.miniGameInfo3;
    this.MINI_GAME_INFO_4 = this.parSheet.miniGameInfoForServer.miniGameInfo4;
    this.MINI_GAME_JACKPOT_RANDOM_SYMBOL_ID = this.parSheet.miniGameInfoForServer.miniGameJackpotRandomSymbolID;
    this.MINI_GAME_GRAND_JACKPOT_INDEX = this.parSheet.miniGameInfoForServer.miniGameGrandJackpotIndex;
    this.MINI_GAME_RANDOM_INFO = this.parSheet.miniGameRandomInfo;
    this.DEFINE_MINI_GAME_TYPE = {
        MINI_GAME_1 : this.parSheet.boardInfo.defineCustomType.miniGame1,
        MINI_GAME_2 : this.parSheet.boardInfo.defineCustomType.miniGame2,
        MINI_GAME_3 : this.parSheet.boardInfo.defineCustomType.miniGame3,
        MINI_GAME_4 : this.parSheet.boardInfo.defineCustomType.miniGame4,
    }

    this.DEFINE_COLLECT_SYMBOL = {
        TOP : this.parSheet.miniGameInfoForServer.defineCollectSymbol.top,
        MID : this.parSheet.miniGameInfoForServer.defineCollectSymbol.mid,
        BOTTOM : this.parSheet.miniGameInfoForServer.defineCollectSymbol.bottom,
    }

    this.MINI_GAME_JACKPOT_SYMBOL_IDS = this.parSheet.miniGameInfoForServer.miniGameJackpotSymbolIDs;
    this.MINI_GAME_DP_SYMBOL_IDS = this.parSheet.miniGameInfoForServer.miniGameDpSymbolIDs;

    // this.HIGH_BALANCE_FREE_SPIN_PROB = this.parSheet.highBalanceFreeSpinProb;//논페이 로직으로 대체

    this.cols = this.parSheet.cols;
    this.rows = this.parSheet.rows;

    this.ACTION_STATE = {
        NORMAL: this.parSheet.actionState.normal,
        BOARD_GAME: this.parSheet.actionState.boardGame,
        CLAIM_BOARD_GAME: this.parSheet.actionState.claimBoardGame,
        WHEEL_SPIN: this.parSheet.actionState.wheelSpin,
        MINI_GAME: this.parSheet.actionState.miniGame,
        CLAIM_MINI_GAME: this.parSheet.actionState.claimMiniGame,
    };
}

RabbitsTrail.prototype.initVariable = function() {
    if (this.TEST_MODE) {
        this.initTestVariable();
    }
    this.initCommonVariable(); // 상시 동기화
    this.initBoardVariable();


    this.initBoardGameVariable();
    this.initWheelSpinVariable();
    this.initMiniGameVariable();
    this.initSyncVariable();
    this.initBoard();
};

RabbitsTrail.prototype.initCommonVariable = function() {
    this.commonVar = {
        actionState : this.ACTION_STATE.NORMAL,
    };
};

RabbitsTrail.prototype.initTestVariable = function () {
    this.testVar = {
        forceToBigWin: false,
        bigWinMultiple: 30,
        toNoWin: false,
        jackpotIndex: -1,
        forceToFreeSpin: false,
        toBoardInfo: {
            toTargetDice: null
        }
    }
};

RabbitsTrail.prototype.initSyncVariable = function () {
    this.syncVar = {
        reelIndex: null,
        rands: null,
        grid: null,
    };
};

RabbitsTrail.prototype.setSyncVariable = function (reelIndex, rands, grid) {
    this.syncVar.reelIndex = reelIndex;
    this.syncVar.rands = rands;
    this.syncVar.grid = grid;
};

RabbitsTrail.prototype.packSyncVariable = function () {
    return {
        reelIndex: this.syncVar.reelIndex,
        rands: this.syncVar.rands,
        grid: this.syncVar.grid,
    };
};

RabbitsTrail.prototype.initBoardVariable = function() {
    let boardStateListIndex = number.genWeightRand( this.BOARD_INFO_FOR_SERVER.initBoardListSelectWeight );
    this.boardVar = {
        boardIndex: boardStateListIndex,//시트의 initBoardList 참고/0 ~ 100 의 Number 값 (HP 와 같은 기능)
        piece: this.BOARD_START_LOCATION,
        miniGameLevel: this.INIT_MINI_GAME_LEVEL[boardStateListIndex],
        baseValue: 0
    };

    //miniGame level 검증 로직
    if(this.INIT_BOARD_LIST[this.boardVar.boardIndex].length !== this.boardVar.miniGameLevel.length)
        logger.debug( 'Slot_237 [initBoardVariable]: board list와 init miniGameLevel 길이가 다름' );

    let boardGameSymbols = this.INIT_BOARD_LIST[this.boardVar.boardIndex];

    for(let i = 0; i < boardGameSymbols.length; i++){
        let boardType = boardGameSymbols[i];
        if(boardType === this.BOARD_GAME_DATA_TYPE.MINI_GAME){
            if(this.boardVar.miniGameLevel[i] === -1){
                logger.debug( 'Slot_237 [initBoardVariable]: miniGame 자리에 level설정이 안 되어있음' );
            }
        }
    }

    // base value계산
    this.boardVar.baseValue = this.getBoardGameBaseValue();

    // this.boardVar = [];
    //
    // for( let i = 0; i < this.betTable.length; i++ ) {
    //     let boardStateListIndex = number.genWeightRand( this.BOARD_INFO_FOR_SERVER.initBoardListSelectWeight );
    //     let object = {
    //         boardIndex: boardStateListIndex,//시트의 initBoardList 참고
    //         centerGauge: this.BOARD_INFO_FOR_SERVER.maxCenterGauge,//0 ~ 100 의 Number 값 (HP 와 같은 기능)
    //         piece: this.BOARD_INFO_FOR_SERVER.boardStartLocation
    //     };
    //     this.boardVar.push( object );
    // }

};

RabbitsTrail.prototype.packBoardVariable = function( ) {
    // return  this.boardVar;
    return {
        boardIndex: this.boardVar.boardIndex,//시트의 initBoardList 참고/0 ~ 100 의 Number 값 (HP 와 같은 기능)
        piece: this.boardVar.piece,
        miniGameLevel: this.boardVar.miniGameLevel
    }
};

RabbitsTrail.prototype.getBoardGameBaseValue = function () {
     let sum = 0;
    let boardTypeList = this.INIT_BOARD_LIST[this.boardVar.boardIndex];
    let boardLevelList = this.boardVar.miniGameLevel;

    for(let i = 0; i < this.BOARD_GAME_LOCATE_PROB_TABLE.length; i++){
        let rowProb = this.BOARD_GAME_LOCATE_PROB_TABLE[i];

        for(let j = 0; j < rowProb.length; j++){
            let prob = rowProb[j];
            let value = this.getValueWithTypeAndLevel(boardTypeList[j], boardLevelList[j], j);
            sum += prob * value;
        }
    }

    //기준 환수율을 계산하여 return
    return sum;
}

RabbitsTrail.prototype.getValueWithTypeAndLevel = function(type, level, index){
    switch( type ) {
        case this.BOARD_INFO.defineState.DP:
            return this.BOARD_PAYBACK_INFO.DP_PAYBACK;
            break;
        case this.BOARD_INFO.defineState.JACKPOT:
            return this.BOARD_PAYBACK_INFO.WHEEL_JACKPOT_PAYBACK;
            break;
        case this.BOARD_INFO.defineState.MINI_GAME:
            //어떤 미니게임인지 파악하고 return하면 된다.
            let miniGameType = this.BOARD_INFO.initCustomBoardList[this.boardVar.boardIndex][index];
            return this.BOARD_PAYBACK_INFO.MINI_GAME_PAYBACK[miniGameType][level];
            break;
        case this.BOARD_INFO.defineState.EMPTY:
        case this.BOARD_INFO.defineState.START:
            return 0;
        default:
            console.log("board type에 저장된 값이 없음.")
    }

}

RabbitsTrail.prototype.initBoardGameVariable = function() {
    this.boardGameVar = {
        totalWin: -1,
        remainRollCount: -1,//주사위 굴리기 남은 횟수, 일반동기화 ( 주사위 더블일 경우 +1 )
        rollCount: -1,//현재까지 던진 주사위 횟수
        rewardList: null,//보드게임 보상에 대한 공용화 프로퍼티, ex) [ { rewardType, commonType, win, jackpotIndex, addRollCount, customData }, ... ]
        dice: null,// ex) [ 1, 1 ], [ 1, 2 ], ..., [ 3, 3 ]
        addRollCount: -1,//리트리거로 인하여 주사위 추가된 총 횟수
        newBoardIndex: -1,//완주시 판 바뀔 때 어떤 판으로 바뀔지에 대한 데이터
        jackpotInfo: null
    };
};

RabbitsTrail.prototype.setBoardGameVariable = function(  ) {
    this.boardGameVar.totalWin = 0;
    this.boardGameVar.remainRollCount = this.INIT_ROLL_COUNT;
    this.boardGameVar.rollCount = 0;
    this.boardGameVar.rewardList = [];
    this.boardGameVar.dice = [-1, -1];
    this.boardGameVar.addRollCount = 0;
    this.boardGameVar.newBoardIndex = -1;
    this.boardGameVar.jackpotInfo = this.jackpotObj.getJackpotInfoForView( this.betCash );
};

RabbitsTrail.prototype.packBoardGameVariable = function() {
    return {
        totalWin: this.boardGameVar.totalWin,
        remainRollCount: this.boardGameVar.remainRollCount,
        rollCount: this.boardGameVar.rollCount,
        rewardList: this.boardGameVar.rewardList,
        dice: this.boardGameVar.dice,
        addRollCount: this.boardGameVar.addRollCount,
        newBoardIndex: this.boardGameVar.newBoardIndex
    };
};

RabbitsTrail.prototype.initWheelSpinVariable = function() {
    this.wheelVar = {
        totalWin: 0,
        jackpotIndex: -1,
        dataForServer : {
            jackpotInfo: null,
            nextState : null
        }
    }
}

RabbitsTrail.prototype.setWheelSpinVariable = function( jackpotInfo, nextState ) {

    this.wheelVar.totalWin = 0;
    this.wheelVar.jackpotIndex = -1;

    this.wheelVar.dataForServer.jackpotInfo = jackpotInfo;
    this.wheelVar.dataForServer.nextState = nextState;
}

RabbitsTrail.prototype.packWheelSpinVariable = function() {
    let v = this.wheelVar;
    let packedFeatureVar = {};
    let keys = Object.keys(v);
    keys.forEach((property)=>{
        if (v.hasOwnProperty(property) && property !== "dataForServer") {
            packedFeatureVar[property] = v[property];
        }
    });
    return packedFeatureVar;
};

RabbitsTrail.prototype.initMiniGameVariable = function () {
    this.miniGameVar = {
        totalWin : -1,
        spinCount       : -1,
        remainSpinCount : -1,
        level: -1,
        gameType: -1,
        customData: null,
        dataForServer: {
            nextState: null,
            jackpotInfo: null,
            prevRands: -1,
            prevReelIndex: -1,
            location: -1
        }
    }
}

RabbitsTrail.prototype.setMiniGameVariable = function( level, type, nextState, jackpotInfo, location ) {
    this.miniGameVar.totalWin = 0;
    this.miniGameVar.spinCount = 0;
    this.miniGameVar.remainSpinCount = this.MINI_GAME_INIT_SPIN_COUNT;
    this.miniGameVar.level = level;
    this.miniGameVar.gameType = type;

    this.miniGameVar.dataForServer.nextState = nextState;
    this.miniGameVar.dataForServer.jackpotInfo = jackpotInfo;
    this.miniGameVar.dataForServer.location = location;

    this.miniGameVar.customData = this.getMiniGameCustomDataForm(type);
    if(type === this.DEFINE_MINI_GAME_TYPE.MINI_GAME_4){
        //lockGrid 생성
        this.miniGameVar.customData.lockGrid = this.getMiniGame4LockGrid();
    }

}

RabbitsTrail.prototype.getMiniGame4LockGrid = function() {
    let lockGrid = this.init2DArray(this.rows, this.cols, -1);

    for(let row = 0; row < this.rows; row++){
        for(let col = 0; col < this.cols - 1; col++){
            if(row === 0){
                lockGrid[row][col] = this.DEFINE_COLLECT_SYMBOL.TOP;
            }else if(row === 1){
                lockGrid[row][col] = this.DEFINE_COLLECT_SYMBOL.MID;
            }else if(row === 2){
                lockGrid[row][col] = this.DEFINE_COLLECT_SYMBOL.BOTTOM;
            }
        }
    }

    return lockGrid;
}

RabbitsTrail.prototype.init2DArray = function( row, col, initValue ) {
    return Array.from( { length: row }, () => Array.from( { length: col }, () => initValue ) );
};

RabbitsTrail.prototype.getMiniGameCustomDataForm = function(type) {
    switch (type) {
        case this.DEFINE_MINI_GAME_TYPE.MINI_GAME_1:
            return {
                randomWildInfo: null
            };
            break;
        case this.DEFINE_MINI_GAME_TYPE.MINI_GAME_2:
            return {
                convertedLongWildInfo: null,
                longWildMultiValue: -1
            };
            break;
        case this.DEFINE_MINI_GAME_TYPE.MINI_GAME_3:
            return {
                multiValue: -1
            };
            break;
        case this.DEFINE_MINI_GAME_TYPE.MINI_GAME_4:
            return {
                lockGrid : null,
                rewardSymbolList: []
            };
            break;
        default:
            console.log("miniGame type error");
    }
}

RabbitsTrail.prototype.packMiniGameVariable = function() {
    let v = this.miniGameVar;
    let packedFeatureVar = {};
    let keys = Object.keys(v);
    keys.forEach((property)=>{
        if (v.hasOwnProperty(property) && property !== "dataForServer") {
            packedFeatureVar[property] = v[property];
        }
    });
    return packedFeatureVar;
};

//동기화 블럭
{
    RabbitsTrail.prototype.writeDefaultGameState = function (player, cb) {
        // return cb();
        let attr = {
            boardVar: this.boardVar,
            // mapVar: this.mapVar
        };

        let copyAttr = common.deepClone(attr);
        userDao.updateDefaultGameSyncData(player.getSlotSyncPlayerID(), parseInt(this.slotID), this.betLines, -1, copyAttr, cb);
    };

    RabbitsTrail.prototype.setInitState = function( res ) {
        if( res.hasOwnProperty( 'betLines' ) && res.hasOwnProperty( 'betPerLine' ) ) {
            this.setTotalBet( res.betLines, res.betPerLine );
        }
        if( res.hasOwnProperty( 'commonVar' ) ) {
            this.commonVar = res.commonVar;
            delete res.commonVar;
            res.nextState = this.commonVar.actionState;
        }
        if( res.hasOwnProperty( 'syncVar' ) ) {
            this.syncVar = res.syncVar;
            delete res.syncVar;
            res.syncVar = this.packSyncVariable();
        }
        if( res.hasOwnProperty( 'boardGameVar' ) ) {
            this.boardGameVar = res.boardGameVar;
            delete res.boardGameVar;
            res.linkVar = this.packBoardGameVariable();
        }
        if( res.hasOwnProperty( 'wheelVar' ) ) {
            this.wheelVar = res.wheelVar;
            delete res.wheelVar;
            res.wheelVar = this.packWheelSpinVariable();
        }
        if( res.hasOwnProperty( 'miniGameVar' ) ) {
            this.miniGameVar = res.miniGameVar;
            delete res.miniGameVar;
            res.miniGameVar = this.packMiniGameVariable();
        }
    };

    RabbitsTrail.prototype.writeGameState = function (player, cb) {
        // return cb();
        if (this.commonVar.actionState === this.ACTION_STATE.NORMAL) return cb();

        let attr = {
            commonVar: this.commonVar,
            syncVar: this.syncVar
        };
        if (this.isMiniGameState(this.commonVar.actionState)) {
            attr.miniGameVar = this.miniGameVar;
        }
        if (this.isBoardGameState(this.commonVar.actionState)) {
            attr.boardGameVar = this.boardGameVar;
        }
        if (this.isWheelSpinState(this.commonVar.actionState)) {
            attr.wheelVar = this.wheelVar;
        }
        userDao.insertGameSyncData(player.getSlotSyncPlayerID(), parseInt(this.slotID), this.betLines, this.betPerLine, 0, 0, false, attr, cb);
    };

    RabbitsTrail.prototype.getDefaultData = function () {
        return {
            boardVar: this.boardVar
        };
    };

    RabbitsTrail.prototype.setDefaultInitState = function (res) {
        if (res.hasOwnProperty('boardVar')) {
            this.boardVar = res.boardVar;
            delete res.boardVar;
            res.boardVar = this.packBoardVariable();
        }
    };
}


RabbitsTrail.prototype.initBoard = function() {
    this.board = new boardObject();
    let startLocation = this.BOARD_START_LOCATION;
    // 슬롯 첫 입장시 betIndex -1 인 경우가 존재하므로 예외처리 해야 함!
    let boardIndex = this.boardVar.boardIndex
    let boardState = this.INIT_BOARD_LIST[ boardIndex ];
    let diceCount = this.DICE_COUNT;
    this.board.init( startLocation, boardState, diceCount );
};

// override
RabbitsTrail.prototype.initPayLines = function () {
    this.maxLine = this.parSheet.payLines.length;
    this.betLines = this.maxLine;

    for( let i = 0; i < this.parSheet.payLines.length; i++ ) {
        let pos      = this.parSheet.payLines[ i ];
        let hexPos   = parseInt( pos, 16 );
        let pPayLine = new slotUtils.PayLine( hexPos, this.parSheet.cols );
        this.payLines.push( pPayLine );
    }
};

// Override
RabbitsTrail.prototype.initReels = function() {
    let i;
    let normalReelCount = slotUtils.getPropertyCount(this.parSheet, "normalReelsType");
    this.miniGameReels = [];

    this.normalReels = [];
    for (i = 0; i < normalReelCount; ++i) {
        this.normalReels[i] = slotUtils.initReel(this.parSheet['normalReelsType' + i], this.parSheet["symbols"].map((sym) => (sym.id)));
        for(let j = 0; j < this.normalReels[i].length; j++){
            this.normalReels[i][j].row = this.parSheet.rows;
        }
    }

    for(let miniGameIndex = 1; miniGameIndex <= this.MINI_GAME_SIZE; miniGameIndex++) {
        let reelCount = slotUtils.getPropertyCount(this.parSheet, "miniGame" + (miniGameIndex) +"ReelsType");

        let reels = [];
        for (i = 0; i < reelCount; ++i) {
            reels[i] = slotUtils.initReel(this.parSheet["miniGame" + (miniGameIndex) +"ReelsType" + i], this.parSheet["symbols"].map((sym) => (sym.id)));
            for(let j = 0; j < reels[i].length; j++){
                reels[i][j].row = this.parSheet.rows;
            }
        }

        this.miniGameReels.push(reels);
    }

    // let miniGame1ReelCount = slotUtils.getPropertyCount(this.parSheet, "miniGame1ReelsType");
    //
    // this.miniGame1Reels = [];
    // for (i = 0; i < miniGame1ReelCount; ++i) {
    //     this.miniGame1Reels[i] = slotUtils.initReel(this.parSheet['miniGame1ReelsType' + i], this.parSheet["symbols"].map((sym) => (sym.id)));
    //     for(let j = 0; j < this.miniGame1Reels[i].length; j++){
    //         this.miniGame1Reels[i][j].row = this.parSheet.rows;
    //     }
    // }
    //
    // let miniGame2ReelCount = slotUtils.getPropertyCount(this.parSheet, "miniGame2ReelsType");
    //
    // this.miniGame2Reels = [];
    // for (i = 0; i < miniGame2ReelCount; ++i) {
    //     this.miniGame2Reels[i] = slotUtils.initReel(this.parSheet['miniGame2ReelsType' + i], this.parSheet["symbols"].map((sym) => (sym.id)));
    //     for(let j = 0; j < this.miniGame2Reels[i].length; j++){
    //         this.miniGame2Reels[i][j].row = this.parSheet.rows;
    //     }
    // }
    //
    // let miniGame3ReelCount = slotUtils.getPropertyCount(this.parSheet, "miniGame3ReelsType");
    //
    // this.miniGame3Reels = [];
    // for (i = 0; i < miniGame3ReelCount; ++i) {
    //     this.miniGame3Reels[i] = slotUtils.initReel(this.parSheet['miniGame3ReelsType' + i], this.parSheet["symbols"].map((sym) => (sym.id)));
    //     for(let j = 0; j < this.miniGame3Reels[i].length; j++){
    //         this.miniGame3Reels[i][j].row = this.parSheet.rows;
    //     }
    // }
    //
    // let miniGame4ReelCount = slotUtils.getPropertyCount(this.parSheet, "miniGame4ReelsType");
    //
    // this.miniGame4Reels = [];
    // for (i = 0; i < miniGame4ReelCount; ++i) {
    //     this.miniGame4Reels[i] = slotUtils.initReel(this.parSheet['miniGame4ReelsType' + i], this.parSheet["symbols"].map((sym) => (sym.id)));
    //     for(let j = 0; j < this.miniGame4Reels[i].length; j++){
    //         this.miniGame4Reels[i][j].row = this.parSheet.rows;
    //     }
    // }


};

RabbitsTrail.prototype.initReelsWeights = function () {
    let i;
    let weightIndex;
    let normalReelCount = slotUtils.getPropertyCount(this.parSheet, "normalReelsType");

    // Init Normal Weight
    this.normalReelsWeight = [];
    for (i = 0; i < normalReelCount; ++i) {
        weightIndex = 'weight';
        this.normalReelsWeight[i] = new reelWeightObject(this.parSheet['normalReelsType' + i], weightIndex, true);
    }

    this.miniGameReelsWeight = [];

    for(let miniGameIndex = 1; miniGameIndex <= this.MINI_GAME_SIZE; miniGameIndex++) {
        let reelCount = slotUtils.getPropertyCount(this.parSheet, "miniGame" + (miniGameIndex) +"ReelsType");

        let weights = [];
        for (i = 0; i < reelCount; ++i) {
            weightIndex = 'weight';
            weights[i] = new reelWeightObject(this.parSheet["miniGame" + (miniGameIndex) +"ReelsType" + i], weightIndex, true);
        }

        this.miniGameReelsWeight.push(weights);
    }

};

RabbitsTrail.prototype.initMiniGameWeights = function () {

    this.miniGameReelSelectWeights = [];
    for(let miniGameIndex = 1; miniGameIndex <= this.MINI_GAME_SIZE; miniGameIndex++) {
        this.miniGameReelSelectWeights.push( this.parSheet['miniGame' + miniGameIndex + 'ReelSelectWeight']);
    }

    this.miniGameWeightSelectWeights = [];
    for(let miniGameIndex = 1; miniGameIndex <= this.MINI_GAME_SIZE; miniGameIndex++) {
        this.miniGameWeightSelectWeights.push( this.parSheet['miniGame' + miniGameIndex + 'WeightSelectWeight']);
    }

};

RabbitsTrail.prototype.internal_reset = function() {
    this.initVariable();
};

RabbitsTrail.prototype.spin = function( msg, next ) {
    let betIndex = msg.betIndex;
    // let betLines = msg.betLines;
    let betLines = this.maxLine;

    this.changeBet( betIndex, betLines );

    //! check : enough balance
    if( this.isEnoughBalance() === false ) {
        logger.debug( '[RabbitsTrail] Spin Fail - short of balance ' );
        next( null, { protocol: msg.protocol, code: code.SLOT.NOT_ENOUGH_BALANCE } );
        return;
    }

    let reelIndex, weightIndex, reels, weight, rands, mysterySymbol, freeSpinCount, isBoardGame, result, nextState, weightSelectWeight;
    let isBuffEnabled = ( this.ownerPlayer.excuteableNewUserBuff() || this.isBuffEnable() );
    let respin = false;
    let respinCount = 0;
    let boardGameMode, payBackRate;
    const MAX_RESPIN_COUNT = 50;
    const nonPaySpin = this.isNonPaySpin();

    //spinMode는 reSpin내에서 영향을 받지 않는다.
    let boardGameModeInfo = this.getBoardGameMode();

    for(let i = 0; i < MAX_RESPIN_COUNT; i++){

        reelIndex = number.genWeightRand( this.NORMAL_REEL_SELECT_WEIGHT );

        // test용 릴 선택: 기본 확률을 위한 환수율 계산 목적
        if(this.TEST_MODE){
            weightSelectWeight = this.NORMAL_WEIGHT_SELECT_WEIGHT;
        }
        // 배포용 릴 선택: 버프, 디버프 확률 적용
        else{
            weightSelectWeight = this.getNormalWeightSelectWeight(boardGameModeInfo, i);
        }
        weightIndex = number.genWeightRand( weightSelectWeight[ reelIndex ] );
        reels = this.normalReels[ reelIndex ];
        weight = this.normalReelsWeight[ reelIndex ];

        //! generate rands
        if( isBuffEnabled ) {
            rands = this.genReelsRands3( reels, weight, weightIndex );
            this.setBuffDisable();
        } else {
            rands = this.genReelsRands3( reels, weight, weightIndex );
        }

        //! test
        this.checkTestFunction( msg, reels, rands );

        //! generate grid
        this.grid = this.genReelsGrid( reels, this.rows );

        //! handle mystery logic
        mysterySymbol = this.MYSTERY_SYMBOL_IDS.map((eachMysterySymbol) => ({
            "mysterySymbolID": eachMysterySymbol,
            "convertedSymbolID": this.replaceSymbolInGrid(this.grid, eachMysterySymbol,
                this.MYSTERY_SYMBOL_CANDIDATE_IDS, this.NORMAL_MYSTERY_SYMBOL_SELECT_WEIGHT, false, false)
        }));
        freeSpinCount = this.checkScatter( reels );
        isBoardGame = freeSpinCount >= this.SCATTER_MATHC_COUNT;

        //! cash out
        result = this.cashOut();

        //! check respin
        if( nonPaySpin ) {
            let isNoWinAndNoFeature = ( result.totalWin === 0 && isBoardGame === false );
            if( isNoWinAndNoFeature === false ) {
                respin = true;
            }
            else{
                respin = false;
            }

        }
        else if(!respin){
            if( boardGameModeInfo.boardGameMode === this.DEFINE_BUFF_PAYBACK_STATE.DE_BUFF){
                if(number.getRandom() < 1 - boardGameModeInfo.payBackRate){
                    respin = true;
                }
            }
        }

        if(isBuffEnabled){
            respin = false;
        }

        if(!respin)
            break;
    }

    nextState = this.ACTION_STATE.NORMAL;

    if(isBoardGame){
        this.setBoardGameVariable();
        this.setSyncVariable(reelIndex, rands, this.grid);
        nextState = this.ACTION_STATE.BOARD_GAME;
    }

    this.commonVar.actionState = nextState;

    let outMsg = {
        protocol     : msg.protocol,
        code         : code.OK,
        action       : msg.action,

        rands        : rands,
        grid         : this.grid,
        reelIndex    : reelIndex,

        result       : result.line,
        totalWin     : result.totalWin,

        nextState    : nextState,
        mysterySymbol: mysterySymbol,
        boardVar     : this.packBoardVariable()
    };

    if(nextState === this.ACTION_STATE.BOARD_GAME)
        outMsg.boardGameVar = this.packBoardGameVariable();

    //! update balance
    this.addWinToJackpot();

    //next( null, outMsg );
    this.updateBalance( this.betCash, result.totalWin );
    userDao.updatePlayerBenefit( this.ownerPlayer, outMsg, next, function( msgArgs, cb ) {
        cb( null, msgArgs );
    } );
};

RabbitsTrail.prototype.getNormalWeightSelectWeight = function(boardGameModeInfo, spinCount){

    switch (boardGameModeInfo.boardGameMode) {
        case this.DEFINE_BUFF_PAYBACK_STATE.NORMAL:
            return this.NORMAL_WEIGHT_SELECT_WEIGHT;

        case this.DEFINE_BUFF_PAYBACK_STATE.BUFF:
            let naturalProb = number.getRandom();//자연확률
            if (naturalProb < boardGameModeInfo.payBackRate - 1)
                return this.NORMAL_WEIGHT_BUFF_SELECT_WEIGHT;
            else
                return this.NORMAL_WEIGHT_SELECT_WEIGHT;

        case this.DEFINE_BUFF_PAYBACK_STATE.DE_BUFF:
            if(spinCount === 0)
                return this.NORMAL_WEIGHT_SELECT_WEIGHT
            else
                return this.NORMAL_WEIGHT_DE_BUFF_SELECT_WEIGHT
        default:
            console.log("노멀 스핀시 버프와 디버프 상황 구분에서 버그 발생");

    }
}

RabbitsTrail.prototype.getBoardGameMode = function(){

    let boardGameModeInfo = {
        boardGameMode: -1,
        payBackRate: -1
    }

    let defaultPayback = this.boardVar.baseValue;
    let currentPayback = this.getBoardGameBaseValue();

    let payBackRate = defaultPayback / currentPayback;
    boardGameModeInfo.payBackRate = payBackRate;

    if(payBackRate === 1){
        boardGameModeInfo.boardGameMode = this.DEFINE_BUFF_PAYBACK_STATE.NORMAL;

    }else if(payBackRate < 1){
        boardGameModeInfo.boardGameMode = this.DEFINE_BUFF_PAYBACK_STATE.DE_BUFF;

    }else if(payBackRate > 1){
        boardGameModeInfo.boardGameMode = this.DEFINE_BUFF_PAYBACK_STATE.BUFF;
    }else{
        console.log("노멀 스핀시 버프와 디버프 상황 구분에서 버그 발생");
    }

    return boardGameModeInfo;
}

RabbitsTrail.prototype.playBoardGame = function( msg, next ) {
    if (!this.checkActionState(msg, next, this.ACTION_STATE.BOARD_GAME, "board game")) {
        return;
    }

    // Init Board and Set Variable
    let boardVar = this.boardVar;
    let boardGameVar = this.boardGameVar;
    let totalWin = 0;
    let totalAddRollCount = 0;
    let isMiniGame = false;
    let isJackpot = false;

    this.updateBoardVar( );

    boardGameVar.rollCount++;
    boardGameVar.remainRollCount--;

    let dice = this.getBoardGameDice();

    let distance = 0;
    dice.forEach( ele => distance += ele );// 주사위를 굴려서 진행한 거리
    boardGameVar.dice = dice;

    // // Roll Dice : Defense Version
    // let isDefenseEnabled = ( boardGameVar.rollCount > 1 && boardVar.piece === 0 && boardGameVar.totalWin === 0 );
    // if( isDefenseEnabled ) {
    //     this.mochaVar.boardGameDefenseCount++;
    //     index = number.genWeightRand( this.BOARD_INFO_FOR_SERVER.defenseInfo.diceCombinationSelectWeight );
    //     dice = this.BOARD_INFO_FOR_SERVER.defenseInfo.diceCombination[ index ];
    //     distance = 0;
    //     dice.forEach( ele => distance += ele );// 주사위를 굴려서 진행한 거리
    //     boardGameVar.dice = dice;
    // }

    // Roll Dice : Test Version
    if( this.TEST_MODE ) {
        if( common.isUndefinedOrNull( this.testVar.toBoardInfo.toTargetDice ) === false ) {
            dice = this.testVar.toBoardInfo.toTargetDice;
            this.testVar.toBoardInfo.toTargetDice = null;
            distance = 0;
            dice.forEach( ele => distance += ele );// 주사위를 굴려서 진행한 거리
            boardGameVar.dice = dice;
        }
    }

    // Move Piece
    let currentLocation = boardVar.piece;
    this.board.movePiece( distance );
    let destinationLocation = this.board.getPiece();
    boardVar.piece = destinationLocation;

    let state = this.board.boardState[ destinationLocation ];
    let stateRewards = null;
    let centerRewards = [];
    let completeRewards = [];
    let info, rewardType, commonType, rewardIndex, rewardSymbol, rewardJackpotIndex, rewardWin;
    let cannonData, shootingDamage, shootingCount, shootingCountIndex, shootingSymbol, shootingJackpotIndex, shootingWin, obj;
    // Update Result 1 - Complete Reward
    // 주의 : isCompleted 완주공식은 주사위를 굴렸을 때 최대진행거리(MAX_DISTANCE)가 보드판 길의 전체길이(this.board.boardState.length)보다 작다는 것을 전제로함.
    // MAX_DISTANCE = 6, dice 의 최대 값은 [ 3, 3 ]
    // this.board.boardState.length = 24
    let isCompleted = ( destinationLocation < currentLocation );
    // Getter Complete Reward
    // Currently No Using
    if( isCompleted ) {
        // 보드판 한바퀴 돌아서 완주했을 경우
        let info = this.BOARD_INFO_FOR_SERVER.completeInfo;
        let rewardCount = info.rewardCount;
        for( let i = 0; i < rewardCount; i++ ) {
            let rewardIndex = number.genWeightRand( info.rewardWeight );
            let rewardSymbol = info.rewardSymbol[ rewardIndex ];
            let rewardJackpotIndex = this.BOARD_GAME_JACKPOT_SYMBOL_IDS.indexOf( rewardSymbol );
            let rewardWin = 0;
            rewardType = this.BOARD_INFO.defineRewardType.COMPLETE;
            commonType = -1;
            let isJackpotSymbol = ( rewardJackpotIndex > -1 );
            let isDirectSymbol = ( this.BOARD_GAME_DP_SYMBOL_IDS.indexOf( rewardSymbol ) > -1 );

            if( isDirectSymbol ) {
                commonType = this.BOARD_INFO.defineCommonType.DP;
                rewardWin = Math.floor( this.getSymbolByID( rewardSymbol ).value * this.betCash );
            } else if( isJackpotSymbol ) {
                commonType = this.BOARD_INFO.defineCommonType.JACKPOT;
                rewardWin = boardGameVar.jackpotInfo[ rewardJackpotIndex ];
            } else {
                continue;
            }
            obj = this.board.getRewardData( rewardType, commonType, rewardWin, rewardJackpotIndex, 0, null, false );
            obj.symbolID = rewardSymbol;
            completeRewards.push( obj );
        }
        rewardType = this.BOARD_INFO.defineRewardType.COMPLETE;
        commonType = this.BOARD_INFO.defineCommonType.RE_TRIGGER;
        let addRollCount = info.addRollCount;
        obj = this.board.getRewardData( rewardType, commonType, 0, -1, addRollCount, null, false );
        completeRewards.push( obj );
    }
    // Setter Complete Reward
    let newBoardIndex = -1;
    if( isCompleted ) {
        for( let i = 0; i < completeRewards.length; i++ ) {
            let reward = completeRewards[ i ];
            boardGameVar.rewardList.push( reward );
            switch( reward.commonType ) {
                case this.BOARD_INFO.defineCommonType.DP:
                    totalWin += reward.win;
                    break;
                case this.BOARD_INFO.defineCommonType.JACKPOT:
                    this.jackpotObj.winJackpot( this.ownerPlayer, reward.jackpotIndex, this.betCash );//잭팟 프로그레시브 초기화 용도
                    totalWin += reward.win;
                    break;
                case this.BOARD_INFO.defineCommonType.RE_TRIGGER:
                    totalAddRollCount += reward.addRollCount;
                    break;
            }
        }
        // newBoardIndex = number.genWeightRand( this.BOARD_INFO_FOR_SERVER.initBoardListSelectWeight );
        // boardVar.boardIndex = newBoardIndex;
        // this.updateBoardVar( this.betIndex );//판 바뀔 때 업데이트 해주기!
        state = this.board.boardState[ destinationLocation ];
    }
    // boardGameVar.newBoardIndex = newBoardIndex;

    // Update Result 2 - Board Reward
    // Getter Board Reward
    switch( state ) {
        case this.BOARD_INFO.defineState.DP:
            rewardType = this.BOARD_INFO.defineRewardType.TILE;
            commonType = this.BOARD_INFO.defineCommonType.DP;
            info = this.BOARD_INFO_FOR_SERVER.stateInfo.direct;
            rewardIndex = number.genWeightRand( info.rewardWeight );
            rewardSymbol = info.rewardSymbol[ rewardIndex ];
            rewardWin = Math.floor( this.getSymbolByID( rewardSymbol ).value * this.betCash );
            stateRewards = this.board.getRewardData( rewardType, commonType, rewardWin, -1, 0, null, false );
            stateRewards.symbolID = rewardSymbol;
            break;
        case this.BOARD_INFO.defineState.JACKPOT:
            isJackpot = true;
            break;
        case this.BOARD_INFO.defineState.MINI_GAME:
            //어떤 미니게임인지 파악하고 return하면 된다.
            isMiniGame = true;
            rewardIndex = this.BOARD_INFO.initCustomBoardList[boardVar.boardIndex][ destinationLocation ];
            break;
        case this.BOARD_INFO.defineState.EMPTY:
        case this.BOARD_INFO.defineState.START:
            break;
        default:
            console.log("define state error");
            break;
    }
    // Change Board Reward Data For Test Mode
    if( this.TEST_MODE ) {
        if( !common.isUndefinedOrNull( stateRewards ) ) {
            switch( stateRewards.rewardType ) {
                case this.BOARD_INFO.defineRewardType.TILE:
                    switch( stateRewards.commonType ) {
                        case this.BOARD_INFO.defineCommonType.JACKPOT:
                            if( this.testVar.jackpotIndex.length > 0 ) {
                                stateRewards.jackpotIndex = this.testVar.jackpotIndex[0];
                                stateRewards.win = boardGameVar.jackpotInfo[ stateRewards.jackpotIndex ];
                                stateRewards.symbolID = this.BOARD_GAME_JACKPOT_SYMBOL_IDS[ stateRewards.jackpotIndex ];
                                this.testVar.jackpotIndex.splice( 0, 1 );
                            }
                            break;
                    }
                    break;
            }
        }
    }
    // Setter Board Reward
    if( !common.isUndefinedOrNull( stateRewards ) ) {
        switch( stateRewards.rewardType ) {
            case this.BOARD_INFO.defineRewardType.TILE:
                switch( stateRewards.commonType ) {
                    case this.BOARD_INFO.defineCommonType.DP:
                        totalWin += stateRewards.win;
                        boardGameVar.rewardList.push( stateRewards );
                        break;
                    case this.BOARD_INFO.defineCommonType.JACKPOT:
                        this.jackpotObj.winJackpot( this.ownerPlayer, stateRewards.jackpotIndex, this.betCash );//잭팟 프로그레시브 초기화 용도
                        totalWin += stateRewards.win;
                        boardGameVar.rewardList.push( stateRewards );
                        break;
                    case this.BOARD_INFO.defineCommonType.COUNT:
                        boardGameVar.goldCount += rewardIndex + 1;
                        boardGameVar.rewardList.push( stateRewards );
                        break;
                }
                break;
            default:
                //시트 양식에 맞게 구성되어 있는지 확인 또는 서버 로직상 버그 있는지 확인
                logger.debug("[Slot_206:Board_Reward_Type_Error] : Server Logic Error Or Sheet Value Error... pls check property named \"boardInfo\" in parSheet");
                break;
        }
    } else {
        if( !common.isUndefinedOrNull( cannonData ) ) {
            for( let i = 0; i < cannonData.length; i++ ) {
                let data = cannonData[ i ];
                let customData = data.customData;
                switch( data.commonType ) {
                    case this.BOARD_INFO.defineCommonType.DP:
                        totalWin += data.win;
                        boardVar.centerGauge -= customData.damage;
                        break;
                    case this.BOARD_INFO.defineCommonType.JACKPOT:
                        this.jackpotObj.winJackpot( this.ownerPlayer, data.jackpotIndex, this.betCash );//잭팟 프로그레시브 초기화 용도
                        totalWin += data.win;
                        boardVar.centerGauge -= customData.damage;
                        break;
                    case this.BOARD_INFO.defineCommonType.NONE:
                        boardVar.centerGauge -= customData.damage;
                        break;
                    default:
                        //시트 양식에 맞게 구성되어 있는지 확인 또는 서버 로직상 버그 있는지 확인
                        logger.debug("[Slot_206:Board_Common_Type_Error] : Server Logic Error Or Sheet Value Error... pls check property named \"boardInfo\" in parSheet");
                        break;
                }
                boardGameVar.rewardList.push( data );
            }
        }
    }

    // Double( Retrigger ) Logic
    let isDouble = false;
    let addRollCountByDouble = 0;
    for( let i = 0; i < dice.length; i++ ) {
        let count = 0;
        for( let j = i; j < dice.length; j++ ) {
            if( dice[ i ] === dice[ j ] ) {
                count++;
            }
        }
        // 같은 눈의 주사위 개수가 2개일 경우
        isDouble = ( count === 2 );
        if( isDouble ) {
            addRollCountByDouble++;
            break;
        }
    }
    totalAddRollCount += addRollCountByDouble;
    boardGameVar.addRollCount = addRollCountByDouble;//더블로 인한 리트리거
    boardGameVar.remainRollCount += totalAddRollCount;//더블로 인한 리트리거 + 보상으로 인한 리트리거

    // set totalWin and actionState
    boardGameVar.totalWin += totalWin;

    if( boardGameVar.remainRollCount > 0 ) {
        this.commonVar.actionState = this.ACTION_STATE.BOARD_GAME;
    } else {
        this.commonVar.actionState = this.ACTION_STATE.CLAIM_BOARD_GAME;
    }

    if(isJackpot){
        this.setWheelSpinVariable(this.boardGameVar.jackpotInfo, this.commonVar.actionState);
        this.commonVar.actionState = this.ACTION_STATE.WHEEL_SPIN;
    }
    else if(isMiniGame){
        //setMiniGame
        this.setMiniGameVariable(this.boardVar.miniGameLevel[destinationLocation], rewardIndex, this.commonVar.actionState, this.boardGameVar.jackpotInfo, destinationLocation);
        this.commonVar.actionState = this.ACTION_STATE.MINI_GAME;
    }

    let outMsg = {
        protocol: msg.protocol,
        code: code.OK,
        action: msg.action,

        totalWin: totalWin,
        nextState: this.commonVar.actionState,
        boardVar: this.packBoardVariable(  ),
        boardGameVar: this.packBoardGameVariable()
    };

    if(isMiniGame){
        outMsg.miniGameVar = this.packMiniGameVariable();
    }

    next( null, outMsg );

    // 초기화
    boardGameVar.rewardList = [];
};

RabbitsTrail.prototype.getBoardGameDice = function (){
    let index = number.genWeightRand( this.DICE_COMBINATION_SELECT_WEIGHT );
    let dice = this.BOARD_INFO_FOR_SERVER.diceInfo.diceCombination[ index ];

    return dice;
}

RabbitsTrail.prototype.claimBoardGame = function( msg, next ) {
    if (!this.checkActionState(msg, next, this.ACTION_STATE.CLAIM_BOARD_GAME, "claim board game")) {
        return;
    }

    let totalWin = this.boardGameVar.totalWin;
    this.commonVar.actionState = this.ACTION_STATE.NORMAL;

    let outMsg = {
        protocol: msg.protocol,
        code: code.OK,
        action: msg.action,

        totalWin: totalWin,
        nextState: this.commonVar.actionState,
        // freeSpinVar: this.packFreeSpinVariable(),
        boardVar: this.packBoardVariable(  ),
        boardGameVar: this.packBoardGameVariable()
    };

    this.updateBalance(0, totalWin, false, 0);
    userDao.updatePlayerBenefit(this.ownerPlayer, outMsg, next, (msgArgs, cb) => {
        cb(null, outMsg);
    });
    this.initBoardGameVariable();
};

RabbitsTrail.prototype.updateBoardVar = function( ) {
    let boardVarElement = this.boardVar;
    let piece = boardVarElement.piece;
    let boardState = this.INIT_BOARD_LIST[ boardVarElement.boardIndex ];

    this.board.setPiece( piece );
    this.board.initBoardState( boardState );
};

RabbitsTrail.prototype.replaceSymbolInGrid = function (grid, id, subSymbols, weight, each, onlyOnce) {
    let s = subSymbols[number.genWeightRand(weight)];
    let subed = [];
    for (let i = 0; i < grid.length; ++i) {
        for (let j = 0; j < grid[i].length; ++j) {
            if (id === grid[i][j]) {
                if (each) {
                    s = subSymbols[number.genWeightRand(weight)];
                    subed.push(s);
                }
                grid[i][j] = s;
                if (!!onlyOnce) {
                    return s;
                }
            }
        }
    }

    if (each)
        return subed;
    else
        return s;
};

RabbitsTrail.prototype.getMiniGameNextLevel = function(currentLevel){
    return (currentLevel + 1) % this.MAX_MINI_GAME_LEVEL;
}

RabbitsTrail.prototype.wheelSpin = function( msg, next ) {
    if( !this.checkActionState( msg, next, this.ACTION_STATE.WHEEL_SPIN, "wheel spin" ) ) {
        return;
    }

    let jackpotRewardWeight = ( this.isGrandJackpotDisabled() ) ? this.WHEEL_JACKPOT_INFO.highBalanceRewardWeight : this.WHEEL_JACKPOT_INFO.rewardWeight ;
    let rewardIndex = number.genWeightRand( jackpotRewardWeight );
    let rewardSymbol = this.WHEEL_JACKPOT_INFO.rewardSymbol[ rewardIndex ];
    let jackpotIndex = this.BOARD_GAME_JACKPOT_SYMBOL_IDS.indexOf( rewardSymbol );

    if(this.TEST_MODE){
        if(this.testVar.jackpotIndex !== -1){
            jackpotIndex = this.testVar.jackpotIndex;
            this.testVar.jackpotIndex = -1;
        }
    }

    this.jackpotObj.winJackpot( this.ownerPlayer, jackpotIndex, this.betCash );
    this.wheelVar.jackpotIndex = jackpotIndex;
    this.wheelVar.totalWin = this.wheelVar.dataForServer.jackpotInfo[jackpotIndex];

    this.commonVar.actionState = this.wheelVar.dataForServer.nextState;

    let outMsg = {
        protocol: msg.protocol,
        code: code.OK,
        action: msg.action,
        totalWin: this.wheelVar.totalWin,
        jackpotIndex: this.wheelVar.jackpotIndex,
        nextState: this.commonVar.actionState,
        // newBoardIndex,
        boardVar: this.packBoardVariable(  ),
        boardGameVar: this.packBoardGameVariable(),
        wheelSpinVar: this.packWheelSpinVariable()
    };

    next( null, outMsg );

    this.boardGameVar.totalWin += this.wheelVar.totalWin;

};

RabbitsTrail.prototype.miniGame = function(msg, next) {
    if( !this.checkActionState( msg, next, this.ACTION_STATE.MINI_GAME, "wheel spin" ) ) {
        return;
    }

    this.miniGameVar.spinCount++;
    this.miniGameVar.remainSpinCount--;

    // console.log(this.miniGameVar.spinCount, this.miniGameVar.gameType);
    // if(this.miniGameVar.spinCount > 50)
    //     console.log();

    let result, totalWin, miniGameInfo, reelIndex, weightIndex, reels, weight, rands;

    miniGameInfo = this.getMiniGameInfo(this.miniGameVar.gameType);
    reelIndex = this.getMiniGameReelIndex(this.miniGameVar.gameType, this.miniGameVar.level);

    //릴 생성 전 배수를 정한다.
    if(this.miniGameVar.gameType === this.DEFINE_MINI_GAME_TYPE.MINI_GAME_2)
        this.miniGameVar.customData.longWildMultiValue = number.genWeightRand(miniGameInfo.levelLongWildWeight[this.miniGameVar.level]);

    // weightIndex = number.genWeightRand(this.miniGameWeightSelectWeights[this.miniGameVar.gameType][reelIndex]);
    weightIndex = this.getMiniGameWeightIndex(this.miniGameVar.gameType, reelIndex);
    reels = this.miniGameReels[this.miniGameVar.gameType][reelIndex];
    weight = this.miniGameReelsWeight[this.miniGameVar.gameType][reelIndex];

    rands = this.genReelsRands3(reels, weight, weightIndex);

    // 패킷 구조 수정됨
    // if(this.miniGameVar.gameType === this.DEFINE_MINI_GAME_TYPE.MINI_GAME_4){
    //
    //     if(this.miniGameVar.spinCount > 1){
    //         let newRands = (this.miniGameVar.dataForServer.prevRands - 1);
    //         if(newRands < 0)
    //             newRands = reels[this.cols - 1].strip.length - 1;
    //         rands[this.cols - 1] = newRands;
    //         reels[this.cols - 1].setStopPos(newRands);
    //         this.miniGameVar.dataForServer.prevRands = newRands;
    //     }else{
    //         this.miniGameVar.dataForServer.prevRands = rands[this.cols - 1];
    //     }
    // }

    this.checkTestFunction( msg, reels, rands );

    this.grid = this.genReelsGrid( reels, this.rows );

    //handle randomInfo
    this.handleRandomSymbol(this.grid, this.MINI_GAME_RANDOM_INFO);

    if(this.miniGameVar.gameType === this.DEFINE_MINI_GAME_TYPE.MINI_GAME_1){

        let randomSymbolCountIndex = number.genWeightRand(miniGameInfo.randomWildCountSelectWeight);
        let randomSymbolCount = miniGameInfo.randomWildCount[randomSymbolCountIndex];

        this.miniGameVar.customData.randomWildInfo = this.getRandomWildList(randomSymbolCount, this.miniGameVar.level, miniGameInfo);
        this.grid = this.setRandomWildSymbol(this.grid, this.miniGameVar.customData.randomWildInfo);
    }
    else if(this.miniGameVar.gameType === this.DEFINE_MINI_GAME_TYPE.MINI_GAME_2){

        this.miniGameVar.customData.convertedLongWildInfo = this.getConvertedLongWildInfo(this.miniGameVar.level, miniGameInfo);
        this.grid = this.setLongWildSymbol(this.grid, this.miniGameVar.customData.convertedLongWildInfo);
    }
    else if(this.miniGameVar.gameType === this.DEFINE_MINI_GAME_TYPE.MINI_GAME_3){

        this.miniGameVar.customData.multiValue = this.getMiniGameMultiValue(this.miniGameVar.level, miniGameInfo);
    }
    else if(this.miniGameVar.gameType === this.DEFINE_MINI_GAME_TYPE.MINI_GAME_4){

        this.grid = this.setLockGrid(this.grid);

    }else{
        console.log("miniGame gameType 버그 발생");
    }

    result = this.cashOut( this.grid );

    totalWin = result.totalWin;

    if(this.miniGameVar.gameType === this.DEFINE_MINI_GAME_TYPE.MINI_GAME_3){
        totalWin = totalWin * this.miniGameVar.customData.multiValue;
    }else if(this.miniGameVar.gameType === this.DEFINE_MINI_GAME_TYPE.MINI_GAME_4){
        let miniGame4Info = this.getMiniGameTotalWin(reels, miniGameInfo);
        totalWin = miniGame4Info.totalWin;
        this.miniGameVar.customData.rewardSymbolList = miniGame4Info.rewardSymbolList;
    }

    this.miniGameVar.totalWin += totalWin;

    this.miniGameVar.remainSpinCount = this.setMiniGameRemainSpinCount(this.miniGameVar.gameType, result, totalWin);

    if(this.miniGameVar.remainSpinCount <= 0){
        this.commonVar.actionState = this.ACTION_STATE.CLAIM_MINI_GAME;
    }

    let outMsg = {
        protocol: msg.protocol,
        code: code.OK,
        action: msg.action,

        reelIndex: reelIndex,
        rands: rands,
        grid: this.grid,

        result: result.line,
        totalWin: totalWin,
        nextState: this.commonVar.actionState,
        miniGameVar : this.packMiniGameVariable()
    };

    next(null, outMsg);
}

RabbitsTrail.prototype.handleRandomSymbol = function( grid, randomInfo ) {
    for( let row = 0; row < grid.length; row++ ) {
        for( let col = 0; col < grid[ row ].length; col++ ) {
            let symbol = grid[ row ][ col ];
            for( let k = 0; k < randomInfo.length; k++ ) {
                let info = randomInfo[ k ];
                let randomSymbol = info.id;
                if( symbol === randomSymbol ) {
                    if(symbol === this.MINI_GAME_JACKPOT_RANDOM_SYMBOL_ID && this.isGrandJackpotDisabled()){
                        //grand jackpot 가중치 0으로 변환
                        info.weight[this.MINI_GAME_GRAND_JACKPOT_INDEX] = 0;
                    }
                    let newSymbol = info.symbol[ number.genWeightRand(info.weight) ];
                    grid[ row ][ col ] = newSymbol;
                }
            }
        }
    }
};

RabbitsTrail.prototype.getMiniGameTotalWin = function (reels, miniGameInfo){
    // let rewardSymbol = grid[miniGameInfo.rewardSymbolRow][miniGameInfo.rewardSymbolCol];
    let totalWin = 0;

    //rands값을 가지고 rewardSymbolList를 생성한다.

    let rewardSymbolList = this.getMiniGameRewardSymbolList(reels, miniGameInfo);

    for(let i = 0; i < rewardSymbolList.length; i++) {
        let rewardSymbol = rewardSymbolList[i];
        if(this.isMiniGameJackpotSymbol(rewardSymbol)){

            let jackpotIndex = this.MINI_GAME_JACKPOT_SYMBOL_IDS.indexOf( rewardSymbol );

            this.jackpotObj.winJackpot( this.ownerPlayer, jackpotIndex, this.betCash );
            this.miniGameVar.customData.jackpotIndex = jackpotIndex;
            totalWin += this.miniGameVar.dataForServer.jackpotInfo[jackpotIndex];
        }
        else if(this.isMiniGameDpSymbol(rewardSymbol)){
            //dp처리
            totalWin += Math.floor( this.getSymbolByID( rewardSymbol ).value * this.betCash );
        }
        else if(this.isMiniGameBlackSymbol(rewardSymbol)){

            totalWin += 0;
        }
        else{
            console.log("miniGame symbol 보상 과정 에러 발생");
        }
    }

    return {
        totalWin: totalWin,
        rewardSymbolList: rewardSymbolList
    };
}

RabbitsTrail.prototype.getMiniGameRewardSymbolList = function(reels, miniGameInfo){
    let rewardIndex = reels[this.cols - 1].stopPos;
    let rewardSymbolList = [];
    let strip = reels[this.cols - 1].strip;

    for(let i = 0; i < strip.length; i++){

        if(rewardIndex < 0 || rewardIndex >= strip.length){
            console.log("rewardIndex값 에러");
            break;
        }

        let rewardSymbol = strip[rewardIndex];

        if(this.isMiniGameBlackSymbol(rewardSymbol))
            break;

        //random symbol 수정
        rewardSymbol = this.handleMiniGameRandomSymbol(rewardSymbol);

        rewardSymbolList.push(rewardSymbol);

        rewardIndex--;
        if(rewardIndex < 0){
            rewardIndex = strip.length - 1;
        }
    }

    return rewardSymbolList;

}

RabbitsTrail.prototype.handleMiniGameRandomSymbol = function(symbolID) {

    let randomInfo = this.MINI_GAME_RANDOM_INFO;
    let symbol = symbolID;

    for( let k = 0; k < randomInfo.length; k++ ) {
        let info = randomInfo[ k ];
        let randomSymbol = info.id;
        if( symbol === randomSymbol ) {
            if(symbol === this.MINI_GAME_JACKPOT_RANDOM_SYMBOL_ID && this.isGrandJackpotDisabled()){
                //grand jackpot 가중치 0으로 변환
                info.weight[this.MINI_GAME_GRAND_JACKPOT_INDEX] = 0;
            }
            symbol = info.symbol[ number.genWeightRand(info.weight) ];
        }
    }

    return symbol;
}

RabbitsTrail.prototype.isMiniGameBlackSymbol = function(symbolID){
    return this.BLANK_SYMBOL_ID === symbolID;
}


RabbitsTrail.prototype.isMiniGameDpSymbol = function(symbolID){
    return this.MINI_GAME_DP_SYMBOL_IDS.indexOf(symbolID) > -1
}

RabbitsTrail.prototype.isMiniGameJackpotSymbol = function(symbolID){
    return this.MINI_GAME_JACKPOT_SYMBOL_IDS.indexOf(symbolID) > -1
}
RabbitsTrail.prototype.setLockGrid = function(grid) {
    let newGrid = common.deepClone(grid);

    for(let row = 0; row < this.rows; row++){
        for(let col = 0; col < this.cols; col++){
            let symbol = this.miniGameVar.customData.lockGrid[row][col];
            if(symbol !== -1)
                newGrid[row][col] = symbol;
        }
    }

    return newGrid;
}

RabbitsTrail.prototype.getMiniGameWeightIndex = function (gameType, reelIndex){

    let weight;

    if(gameType === this.DEFINE_MINI_GAME_TYPE.MINI_GAME_2){
        weight = this.miniGameWeightSelectWeights[gameType][reelIndex][this.miniGameVar.customData.longWildMultiValue]
    }else{
        weight = this.miniGameWeightSelectWeights[gameType][reelIndex]
    }

    return number.genWeightRand(weight);
}

RabbitsTrail.prototype.setLongWildSymbol = function(grid, convertedLongWildInfo){
    let newGrid = common.deepClone(grid);

    for(let i = 0; i < convertedLongWildInfo.length; i++){
        let info = convertedLongWildInfo[i];
        newGrid[info.row][info.col] = info.id;
    }

    return newGrid;
}

RabbitsTrail.prototype.getMiniGameMultiValue = function (level, info) {
    let multiValueInfo = info.multiValueInfo[level];
    let multiValueIndex = number.genWeightRand(multiValueInfo.multiValueWeight);
    let multiValue = multiValueInfo.multiValue[multiValueIndex];

    return multiValue;
}

RabbitsTrail.prototype.getConvertedLongWildInfo = function (level, info) {
    let longWildSymbolIds = info.multiLongWildInfo[this.miniGameVar.customData.longWildMultiValue];
    let convertedLongWildInfo = [];
    let col = info.longWildColIndex;

    for(let row = 0; row < this.rows; row++){
        convertedLongWildInfo.push({
            row: row,
            col: col,
            id: longWildSymbolIds[row]
        })
    }

    return convertedLongWildInfo;
}

RabbitsTrail.prototype.claimMiniGame = function( msg, next ) {
    if (!this.checkActionState(msg, next, this.ACTION_STATE.CLAIM_MINI_GAME, "claim mini game")) {
        return;
    }

    let totalWin = this.miniGameVar.totalWin;
    this.boardGameVar.totalWin += totalWin;

    //set nextState
    this.commonVar.actionState = this.miniGameVar.dataForServer.nextState;

    //update miniGameLocation
    let miniGameCurrentLevel = this.boardVar.miniGameLevel[this.miniGameVar.dataForServer.location];
    this.boardVar.miniGameLevel[this.miniGameVar.dataForServer.location] = this.getMiniGameNextLevel(miniGameCurrentLevel);

    let outMsg = {
        protocol: msg.protocol,
        code: code.OK,
        action: msg.action,
        totalWin: totalWin,
        nextState: this.commonVar.actionState,
        boardVar: this.packBoardVariable(),
        miniGameVar: this.packMiniGameVariable(),
        bordGameVar: this.packBoardGameVariable()
    }

    this.initMiniGameVariable();

    next(null, outMsg);
};

RabbitsTrail.prototype.setMiniGameRemainSpinCount = function( gameType, result, totalWin ) {

    if(gameType === this.DEFINE_MINI_GAME_TYPE.MINI_GAME_2){
        if(result.totalWin > 0)
            this.miniGameVar.remainSpinCount++;
    }else if(gameType === this.DEFINE_MINI_GAME_TYPE.MINI_GAME_3){

        if(result.totalWin <= 0)
            this.miniGameVar.remainSpinCount++;
    }
    // else if(gameType === this.DEFINE_MINI_GAME_TYPE.MINI_GAME_4){
    //     if(totalWin > 0)
    //         this.miniGameVar.remainSpinCount++;
    // }

    if(this.miniGameVar.spinCount > 1000){
        console.log("miniGame 무한 스핀 발생: ", gameType)
        this.miniGameVar.remainSpinCount = 0;
    }


    return this.miniGameVar.remainSpinCount;
}

RabbitsTrail.prototype.setRandomWildSymbol = function( grid, randomSymbolList ) {
    let newGird = common.deepClone(grid);
    for(let i = 0; i < randomSymbolList.length; i++){
        let randomSymbolInfo = randomSymbolList[i];
        newGird[randomSymbolInfo.row][randomSymbolInfo.col] = randomSymbolInfo.id;
    }
    return newGird;
}

RabbitsTrail.prototype.getRandomWildList = function (randomSymbolCount, level, miniGameInfo) {

    //level에 따라배수 wild로 바꿔줌

    let randomSymbolInfoList = [];
    let randomWildInfo = [];
    for(let row = 0; row < this.rows; row++){
        for(let col = 0; col < this.cols; col++){
            randomSymbolInfoList.push({
                id: miniGameInfo.randomWildSymbolID,
                row: row,
                col: col
            });
        }
    }

    randomWildInfo = number.getRandomMultiValueFromArray(randomSymbolInfoList, randomSymbolCount);

    // console.log(randomWildInfo);

    if(randomWildInfo.length < level + 1)
        console.log("wild 갯수 부족 현상 발생 !");

    for(let i = 0; i < level + 1; i++){
        randomWildInfo[i].id = miniGameInfo.randomMultiWildSymbolID;
    }

    return common.shuffleArray(randomWildInfo);
}

RabbitsTrail.prototype.getMiniGameReelIndex = function(gameType, level) {
    let reelIndex = -1;
    let miniGameReelSelectWeight = this.miniGameReelSelectWeights[gameType];

    if(gameType === this.DEFINE_MINI_GAME_TYPE.MINI_GAME_4)
        reelIndex = level;
    else
        reelIndex = number.genWeightRand(miniGameReelSelectWeight);

    return reelIndex;
}

RabbitsTrail.prototype.getMiniGameInfo = function(gameType) {
    return this.MINI_GAME_INFO["miniGameInfo" + (gameType + 1)];
}

RabbitsTrail.prototype.customAction = function( msg, next ) {
    let sendMsg = {};

    switch( msg.action ) {
        case this.ACTION_STATE.BOARD_GAME://200
            this.playBoardGame( msg, next );
            break;
        case this.ACTION_STATE.CLAIM_BOARD_GAME://250
            this.claimBoardGame( msg, next );
            break;
        case this.ACTION_STATE.MINI_GAME: //350
            this.miniGame(msg, next);
            break;
        case this.ACTION_STATE.CLAIM_MINI_GAME: //350
            this.claimMiniGame(msg, next);
            break;
        default:
            sendMsg.code = code.FAIL;
            sendMsg.ERROR_CODE = 'Protocol Error';
            return next( null, sendMsg );
    }
};

RabbitsTrail.prototype.cashOut = function() {
    let result = {
        line: [],
        totalWin: 0,
    };

    let grid = this.grid;

    ///////////////////////////
    // Payout
    ///////////////////////////
    for ( let i = 0; i < this.payLines.length; i++ ) {
        let payLine = this.payLines[ i ];
        payLine.reset();

        let o = this.matchSymbol( grid, payLine, this.WILD_SYMBOL_IDS );

        if( o.win > 0 ) {
            o.lineIndex = i;
            result.totalWin += o.win;

            delete o.name;
            delete o.wildCount;

            result.line.push( o );
        }
    }

    if( this.TEST_MODE ) {
        if( this.testVar.toNoWin ) {
            this.testVar.toNoWin = false;
            result = [];
            result.totalWin = 0;
            result.jackpot = false;
        }
        if( this.testVar.forceToBigWin ) {
            this.testVar.forceToBigWin = false;
            if( result.length > 0 ) {
                // 라인페이가 있을 경우 totalWin 만 빅윈 추가
                result.totalWin += this.betCash * this.testVar.bigWinMultiple;
            } else {
                // 라인페이가 없을 경우 더미 라인페이 추가
                result = [];
                result.totalWin = 0;
                result.jackpot = false;
                let dummyLineIndex = 0;
                let dummyMatchCount = this.cols;
                let dummyWin = this.betCash * this.testVar.bigWinMultiple;
                // let dummyLine = "0x00000";//올웨이즈 라인의 더미 데이터!
                let dummyObj = {
                    lineIndex: dummyLineIndex,
                    matchCount: dummyMatchCount,
                    matchSymbolID: grid[ 0 ][ 0 ],
                    // line            : dummyLine,//올웨이즈 라인의 더미 데이터!
                    win: dummyWin
                };
                result.push( dummyObj );
                result.totalWin = dummyWin;
            }
        }
    }

    return result;
};

RabbitsTrail.prototype.matchSymbol = function( grid, payLine, wildID ) {
    // match stop symbol
    for( var c = 0; c < payLine.position.length; c++ ) {
        var r = payLine.position[c];
        payLine.stopSymIDs[c] = grid[r][c];
    }

    var o = {
        win: 0,
        matchSymbolID: -1,
        name: '',
        matchCount: '',
        lineIndex: -1
    };

    var i;
    for( var s = 0; s < this.symbols.length; s++ ) {
        var symbol = this.symbols[s];

        var wildCount = 0;
        for( i = 0; i < payLine.stopSymIDs.length; i++ ) {
            if( this.isWildSymbol(payLine.stopSymIDs[ i ]) ) {
                wildCount++;
            } else {
                break;
            }
        }

        var wildTotalCount = 0;
        for( i = 0; i < payLine.stopSymIDs.length; i++ ) {
            if( this.isWildSymbol(payLine.stopSymIDs[ i ]) ) {
                wildTotalCount++;
            }
        }

        var matchCount = 0;
        for( i = 0; i < payLine.stopSymIDs.length; i++ ) {
            if( this.isWildSymbol(payLine.stopSymIDs[ i ]) || (payLine.stopSymIDs[i] === symbol.id) ) {
                matchCount++;
            } else {
                break;
            }
        }

        if ( (matchCount === wildCount) && !this.isWildSymbol(payLine.stopSymIDs[ i ]) ) {
            // wild 심볼 2개 + bonus 심볼인 경우에는 bonus 3개로 쳐주어야 하나 bonus 심볼은 pay 0
            // 그러므로 2개일 때 pay가 되는 다른 심볼로 체크되는 문제 발생하여 continue 해주어야함
            continue;
        }

        if( matchCount > 0 ) {
            // console.log(symbol.payout);
            var temp = this.betPerLine * symbol.payout[ matchCount - 1 ];
            if( temp > o.win ) {
                // payLine.stopSymIDs = [102,102,102];
                let mulValue = this.getMulValue(payLine.stopSymIDs, matchCount);
                o.win = temp * mulValue;
                o.matchSymbolID = symbol.id;
                o.name = symbol.name;
                o.matchCount = matchCount;
                o.wildCount = wildTotalCount;
            }
        }
    }

    return o;
};

RabbitsTrail.prototype.getMulValue = function (stopSymIDs, matchCount){
    let mulValue = 1;

    for(let i = 0; i < matchCount; i++ ) {

        let symbolID = stopSymIDs[i];

        if(this.isMulWildSymbol(symbolID)){
            mulValue *= this.getSymbolByID(symbolID).mulValue;

        }
    }
    return mulValue;
}

RabbitsTrail.prototype.isMulWildSymbol = function(symbolID){
    return this.MUL_WILD_SYMBOL_IDS.indexOf( symbolID ) > -1;
}

RabbitsTrail.prototype.isWildSymbol = function (symbolID){
    return this.WILD_SYMBOL_IDS.indexOf(symbolID) > -1;
}

RabbitsTrail.prototype.checkScatter = function( reels ) {
    return this.checkSymbol( reels, this.SCATTER_SYMBOL_ID );
};

RabbitsTrail.prototype.isMatchedScatter = function( reels ) {
    return this.checkScatter( reels ) >= 3;
};

RabbitsTrail.prototype.checkTestFunction = function( msg, reels, rands ) {
    if( this.TEST_MODE ) {
        if( typeof msg.debugSlotFunctionName === 'string' && typeof this[ msg.debugSlotFunctionName ] === 'function' ) {
            this[ msg.debugSlotFunctionName ]( reels, rands );
            delete msg.debugSlotFunctionName;
        } else if( msg.hasOwnProperty( 'debugSlotRands' ) && Array.isArray( msg.debugSlotRands ) === true ) {
            if( msg.debugSlotRands.length === reels.length ) {
                let copyRands = this.testRands.apply( this, [ reels ].concat( msg.debugSlotRands ) );
                for( let i = 0; i < copyRands.length; ++i ) {
                    rands[ i ] = copyRands[ i ];
                }
                delete msg.debugSlotRands;
            }
        }
    }
};

RabbitsTrail.prototype.checkActionState = function( msg, next, correctActionState, name ) {
    if( this.commonVar.actionState !== correctActionState ) {
        logger.debug( `[RabbitsTrail] ${name} Fail - Wrong mode `, this.commonVar.actionState );
        next( null, { protocol: msg.protocol, code: code.SLOT.DISABLE_SPIN } );
        return false;
    }
    return true;
};

RabbitsTrail.prototype.isMiniGameState = function(actionState){
    return actionState === this.ACTION_STATE.MINI_GAME || actionState === this.ACTION_STATE.CLAIM_MINI_GAME;
}

RabbitsTrail.prototype.isBoardGameState = function(actionState){
    return actionState === this.ACTION_STATE.BOARD_GAME || actionState === this.ACTION_STATE.CLAIM_BOARD_GAME;
}

RabbitsTrail.prototype.isWheelSpinState = function(actionState){
    return actionState === this.ACTION_STATE.WHEEL_SPIN;
}

RabbitsTrail.prototype.toScatter = function( reels, rands, count ) {
    let c = this.SCATTER_SYMBOL_ID;
    let counts = [ 0, 0, 0 ];
    for(let  i = 0; i < count; i++){
        counts[i] = 1;
    }

    common.shuffleArray(counts);

    let testRand = this.genRandsBySymbolIDCount(reels, [c, c, c], counts);

    for (let i = 0; i < rands.length; i++) {
        rands[i] = testRand[i];
        reels[i].setStopPos(rands[i]);
    }
};

RabbitsTrail.prototype.toBigWin = function( reels, rands ) {
    this.testVar.forceToBigWin = true;
};

RabbitsTrail.prototype.toNoWin = function( reels, rands ) {
    if( this.commonVar.actionState === this.ACTION_STATE.NORMAL ) {
        this.testVar.toNoWin = true;
    }
};

RabbitsTrail.prototype.toScatter3 = function( reels, rands ) {
    if(this.commonVar.actionState !== this.ACTION_STATE.NORMAL){
        return;
    }
    this.toScatter(reels, rands, 3);
};

RabbitsTrail.prototype.toBoardGameDoubleDice = function( reels, rands ) {
    if( this.commonVar.actionState !== this.ACTION_STATE.NORMAL ) {
        return;
    }
    this.toScatter( reels, rands, 3 );
    let doubleDiceList = [ [ 1, 1 ], [ 2, 2 ], [ 3, 3 ] ];
    this.testVar.toBoardInfo.toTargetDice = number.getRandomValueFromArray( doubleDiceList );
};

RabbitsTrail.prototype.toSetDice = function( targetState ) {
    let boardVar = this.boardVar;
    let boardIndex = boardVar.boardIndex;
    let piece = boardVar.piece;
    let distance = -1;
    let diceCount = this.BOARD_INFO.diceCount;
    const MIN_DICE_DISTANCE = 1;
    const MAX_DICE_DISTANCE = 3;
    const MIN_DISTANCE = MIN_DICE_DISTANCE * diceCount;
    const MAX_DISTANCE = MAX_DICE_DISTANCE * diceCount;
    for( let i = 0; i < MAX_DISTANCE; i++ ) {
        let coordinate = number.positiveModulo( piece + i + 1, this.BOARD_INFO.initBoardList[ boardIndex ].length );
        let state = this.BOARD_INFO.initBoardList[ boardIndex ][ coordinate ];
        if( state === targetState ) {
            distance = i + 1;
            break;
        }
    }
    if( distance === -1 ) {
        distance = MAX_DISTANCE;
    }
    let isValidDistance = ( MIN_DISTANCE <= distance && distance <= MAX_DISTANCE );
    if( isValidDistance === false ) {
        // 서버 로직 오류 or 주사위 정보를 담은 상수 데이터 오류
        return;
    }
    if( distance > MAX_DISTANCE / diceCount ) {
        let leftDice = MAX_DICE_DISTANCE;
        let rightDice = distance - leftDice;
        this.testVar.toBoardInfo.toTargetDice = [ leftDice, rightDice ];
    } else {
        let leftDice = MIN_DICE_DISTANCE;
        let rightDice = distance - MIN_DICE_DISTANCE;
        this.testVar.toBoardInfo.toTargetDice = [ leftDice, rightDice ];
    }
};

RabbitsTrail.prototype.toBoardGameMiniJackpot = function( reels, rands ) {
    if( this.commonVar.actionState !== this.ACTION_STATE.NORMAL ) {
        return;
    }
    this.toScatter( reels, rands, 3 );
    this.toSetDice( this.BOARD_INFO.defineState.JACKPOT );
    this.testVar.jackpotIndex = 0;
};

RabbitsTrail.prototype.toBoardGameMinorJackpot = function( reels, rands ) {
    if( this.commonVar.actionState !== this.ACTION_STATE.NORMAL ) {
        return;
    }
    this.toScatter( reels, rands, 3 );
    this.toSetDice( this.BOARD_INFO.defineState.JACKPOT );
    this.testVar.jackpotIndex = 1;
};

RabbitsTrail.prototype.toBoardGameMajorJackpot = function( reels, rands ) {
    if( this.commonVar.actionState !== this.ACTION_STATE.NORMAL ) {
        return;
    }
    this.toScatter( reels, rands, 3 );
    this.toSetDice( this.BOARD_INFO.defineState.JACKPOT );
    this.testVar.jackpotIndex = 2;
};

RabbitsTrail.prototype.toBoardGameMegaJackpot = function( reels, rands ) {
    if( this.commonVar.actionState !== this.ACTION_STATE.NORMAL ) {
        return;
    }
    this.toScatter( reels, rands, 3 );
    this.toSetDice( this.BOARD_INFO.defineState.JACKPOT );
    this.testVar.jackpotIndex = 3;
};

RabbitsTrail.prototype.toBoardGameGrandJackpot = function( reels, rands ) {
    if( this.commonVar.actionState !== this.ACTION_STATE.NORMAL ) {
        return;
    }
    this.toScatter( reels, rands, 3 );
    this.toSetDice( this.BOARD_INFO.defineState.JACKPOT );
    this.testVar.jackpotIndex = 4;
};

RabbitsTrail.prototype.toBoardGameMiniGame = function( reels, rands ) {
    if( this.commonVar.actionState !== this.ACTION_STATE.NORMAL ) {
        return;
    }
    this.toScatter( reels, rands, 3 );
    this.toSetDice( this.BOARD_INFO.defineState.MINI_GAME );
};

