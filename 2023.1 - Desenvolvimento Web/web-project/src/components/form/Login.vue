


<script>

import { ref } from 'vue';
import { Auth } from '../../stores/user.js';
import router from '../../router';



export default {
    data() {
        return {
            remember: ref(false),
            auth: Auth(),
            loginSucess: ref(null),
            loginError: ref(null),
            email: '',
            password: '',
            remember: ref(false),
        }
    },
    methods: {
        async login() {
            if(!this.email || !this.password){
                this.$emit('erro', 'Campo Obrigatório Não Preenchido')
                this.$refs.loginError.click()
                return 
            }

            const res = await this.auth.login(this.email, this.password)
            if (res == '200') {
                if (await this.auth.role == 'Admin') {
                    // this.auth.getUserAds()
                    router.push('/admin')
                    return 
                }
                if (!this.remember) {
                    this.email = ''
                    this.password = ''
                }
                
                this.$refs.loginSucess.click()

            } else {
                this.$emit('erro', res.message)
                this.$refs.loginError.click()

            }
        }
    }, 
    inheritAttrs: false

}

</script>


<template>
    <button type="button" data-bs-toggle="offcanvas" data-bs-target="#userOpt" ref="loginSucess" style="display: none;">
    </button>
    <button type="button" data-bs-toggle="offcanvas" data-bs-target="#loginError" ref="loginError" style="display: none;">
    </button>

    <form class="float-start" @submit.prevent="login()">
        <!-- formulario -->
        <div class="form-group">

            <!-- email -->
            <input id="eLogin" v-model="email" type="text" class="form-control m-3" aria-describedby="emailHelp"
                placeholder="Email ou Usuário" autocomplete="email">

            <!-- Senha -->
            <input id="pLogin" autocomplete="password" v-model="password" type="password" class="form-control m-3" placeholder="Senha">
        </div>

        <!-- button -->
        <button type="submit" class="btn btn-primary float-start ms-4" data-bs-dismiss="offcanvas">Login</button>
        <div class="form-group form-check float-end">

            <input autocomplete="off" id="cLogin" type="checkbox" class="form-check-input" v-model="remember">
            <label class="form-check-label" for="cLogin"><small>Lembrar</small></label>
        </div>


    </form>

</template>