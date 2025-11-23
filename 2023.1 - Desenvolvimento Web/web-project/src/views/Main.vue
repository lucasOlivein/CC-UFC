<script setup>
import Headerr from '../components/header/Header.vue';
import Categories from '../components/menus/Categories.vue';


import SideMenu from '../components/menus/sideMenu.vue';
import { Ads } from '../stores/ads';
const ads = Ads()


function search(event){
    ads.filterResult = event
}
</script>


<template>
    

    <SideMenu />
    <div class="container">
        <div class="row">
            <Headerr :home="'/'" :ads="ads.anuncios" @result="ads.search"/>
        </div>

        <div class="row">
            <div class="col-9">
                <router-view></router-view>
            </div>
            <div class="col-3">
                <Categories :In="'/categoria/'" :Out="'/'" :user="true"/>
            </div>

        </div>


    </div>
</template>