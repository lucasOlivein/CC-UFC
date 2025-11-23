<script>
import { Auth } from '../stores/user'
import SideMenu from '../components/menus/SideMenu.vue'
import UserAds from '../components/ads/user/AuthAds.vue'
import router from '../router'
import { onMounted } from 'vue'

import Categories from '../components/menus/Categories.vue'
export default {
  components: {
    SideMenu,
    UserAds,
    Categories
},

  data() {
    return {
      updateBut: 'Editar',
      auth: Auth(),


      tittleTemp: '',
      descriptionTemp: '',

    }
  },
}

</script>

<template>
  <div>
    <SideMenu />
  </div>


  <div class="container-fluid mb-5">
    <h5 class="position-relative float-start mt-2">Anuncios</h5>
    <button type="button mr-4" class="btn position-relative float-center" data-bs-toggle="offcanvas"
      data-bs-target="#userAds" style="text-align: center;">Adicionar Anuncio</button>
    <button type="button" class="btn position-relative float-end" id="adm"><router-link
        to="/">voltar</router-link></button>
  </div>


  <div class="container">
    <div class="row">
      <div class="col-9">
        <router-view></router-view>
      </div>
      
    </div>
  </div>
</template>